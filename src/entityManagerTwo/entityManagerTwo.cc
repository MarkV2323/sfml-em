#include "entityManagerTwo.h"

namespace em {

EntityManagerTwo::EntityManagerTwo() {}

EntityManagerTwo::~EntityManagerTwo() {
    // Cleanup all entities is automatically done due
    // to private data attributes going out of scope.
}

S_entity EntityManagerTwo::addEntity(const std::string & tag) {
    // Have to use a special case of make_shared, should be exception safe due
    // to only passing a single arguement. Has to deal with private Entity
    // constructor.
    m_toAddEntites.push_back(S_entity(new Entity(tag, m_totalEntities++)));
    return m_toAddEntites.back();
}

EntityVecTwo& EntityManagerTwo::getEntities() {
    return m_entities;
}

EntityVecTwo& EntityManagerTwo::getEntities(const std::string & tag) {
    return m_entityMap[tag];
}

EntityMapTwo& EntityManagerTwo::getEntityMap() {
    return m_entityMap;
}

void EntityManagerTwo::update() {
    // Add
    for (auto& e : m_toAddEntites) {
        m_entities.push_back(e);
        m_entityMap[e->tag()].push_back(e);
    }
    m_toAddEntites.clear();
    
    // Remove
    m_entities.erase(std::remove_if(m_entities.begin(), m_entities.end(),
    [](S_entity entity) {
        return !entity.get()->m_alive;
    }), m_entities.end());

    for(auto& em: m_entityMap) {
        em.second.erase(std::remove_if(em.second.begin(), em.second.end(),
        [](S_entity entity) {
            return !entity.get()->m_alive;
        }), em.second.end());
    }
}

size_t EntityManagerTwo::getTotalCreatedEntities() {
    return m_totalEntities;
}

size_t EntityManagerTwo::getTotalAliveEntities() {
    return m_entities.size();
}

size_t EntityManagerTwo::getTotalWaitingEntities() {
    return m_toAddEntites.size();
}

}