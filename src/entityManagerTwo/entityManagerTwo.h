#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>

#include "entities/entity.h"

namespace em {

using S_entity = std::shared_ptr<Entity>;
using EntityVecTwo = std::vector<S_entity>;
using EntityMapTwo = std::map<std::string, EntityVecTwo>;

// EntityManagerTwo uses shared_ptr rather than raw pointers when
// compared to EntityManager.
class EntityManagerTwo
{
private:
    EntityVecTwo m_entities;
    EntityVecTwo m_toAddEntites;
    EntityMapTwo m_entityMap;
    size_t m_totalEntities = 0;
public:
    // Public Constructor for an EntityManagerTwo object
    EntityManagerTwo();

    // Public Deconstrctor for this EntityMangerTwo
    ~EntityManagerTwo();

    // Create an entity
    Entity* addEntity(const std::string& tag);
    
    // Access the total entity vector
    EntityVecTwo& getEntities();

    // Access the tagged entity vector
    EntityVecTwo& getEntities(const std::string& tag);

    // Access the entity map containing all tagged entity vectors
    EntityMapTwo& getEntityMap();

    // Update entities in m_toAddEntites
    void update();
    
    // Return the total number of created entities by this EntityManagerTwo 
    size_t getTotalCreatedEntities();

    // Return the total number of entities with alive being true
    size_t getTotalAliveEntities();

    // Return the total number of entities waiting to be added to the entity vectors
    size_t getTotalWaitingEntities();
};

}