#include "entityManager.h"

namespace em {

EntityManager::EntityManager() {}

EntityManager::~EntityManager() {
    // Cleanup all entities
    for (auto e : m_entities) {
        if (e != nullptr) {
            std::cout << "Deleting Entity: " << e->m_id << "\n";
            delete e;
        }
    }
}

Entity* EntityManager::addEntity(const std::string & tag) {
    auto e = new Entity(tag, m_totalEntities++);
    m_toAddEntites.push_back(e);
    return e;
}

void EntityManager::removeEntity(Entity & e) {
    e.kill();
}

EntityVec& EntityManager::getEntities() {
    return m_entities;
}

EntityVec& EntityManager::getEntities(const std::string & tag) {
    return m_entityMap[tag];
}

void EntityManager::update() {
    // Add
    for (auto& e : m_toAddEntites) {
        m_entities.push_back(e);
        m_entityMap[e->tag()].push_back(e);
    }
    m_toAddEntites.clear();
    /*
    Remove
        Due to raw pointers and need to avoid iterator invalidation, we 
        must start our remove by recording pairs of indicies of Entities
        that have been marked for death.
        
        1 - Create vector to hold pairs of indicies.
        2 - Iterate over all entities, record pair.first indicie from m_entities
        3 - Iterate over m_entityMap[e->m_tag] to record pair.second indicie
        
        Now we know where our Entity that needs to be removed is located in both
        the total entity vector, and the specific mapping one.

        1 - Iterate over deathIndicies
        2 - Record Entity tag in tmp_tag
        2 - Delete Entity 
        3 - Set to nullptr in m_entities.at(p.first)
        4 - Set to nullptr in m_entityMap[tmp_tag].at(p.second)

        Something to consider: We never actually reduce the size of our m_entities or m_entityMap.
        What this does is free the entities memmory, and set it's pointer to nullptr.
        The question becomes, what is better for performance
            A: Erasing nullptrs immediatly upon free
            B: In batches once a certain number has built up
        * Erasing requires relocate to new positions.
    */
    std::vector<std::pair<int, int>> deathIndicies = std::vector<std::pair<int, int>>();
    int i = 0;
    std::pair<int, int> i_pair = {0, 0};
    for (auto& e : m_entities) {
        if (e->m_alive == false) {
            std::cout << "Entity ID: " << e->m_id << " has been marked for death" << "\n";
            i_pair.first = i;
            
            int j = 0;
            bool found_second = false;
            for (auto& em : m_entityMap[e->m_tag]) {
                if (em->m_id == e->m_id) {
                    i_pair.second = j;
                    found_second = true;
                    break;
                }
                ++j;
            }

            // Found both indicie pair sucessfully
            if (found_second) {
                std::cout << "Entity ID: " << e->m_id << " has an indicie pair of " 
                    << i_pair.first << ",[" << e->m_tag << "]" << i_pair.second << "\n";
                deathIndicies.push_back(i_pair);
            } else {
                std::cout << "ERROR: UNABLE TO FIND SECOND INDICIE FOR " << e->m_id << " " << e->m_tag << "\n";
            }

        }
        ++i;
    }

    i = 0;
    for (auto& p : deathIndicies) {
        std::cout << "Entity ID: " << m_entities.at(p.first - i)->m_id << " will be freed and set to nullptr" << "\n";
        auto tmp_tag = m_entities.at(p.first - i)->m_tag;
        delete m_entities.at(p.first - i);
        m_entities.at(p.first - i) = nullptr;
        m_entityMap[tmp_tag].at(p.second - i) = nullptr;

        // Erase and relocate everytime
        std::cout << "Before removal total entities size: " << m_entities.size() << "\n";
        std::cout << "Before removal Map entities size:   " << m_entityMap[tmp_tag].size() << "\n";
        m_entities.erase(m_entities.begin() + p.first - i);
        m_entityMap[tmp_tag].erase(m_entityMap[tmp_tag].begin() + p.second - i);
        std::cout << "After removal total entities size: " << m_entities.size() << "\n";
        std::cout << "After removal Map entities size:   " << m_entityMap[tmp_tag].size() << "\n";
        ++i;
    }
}

size_t EntityManager::getTotalCreatedEntities() {
    return m_totalEntities;
}

size_t EntityManager::getTotalAliveEntities() {
    return m_entities.size();
}

size_t EntityManager::getTotalWaitingEntities() {
    return m_toAddEntites.size();
}


}