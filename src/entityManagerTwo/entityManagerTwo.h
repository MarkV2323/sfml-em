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
    EntityManagerTwo();
    ~EntityManagerTwo();

    S_entity addEntity(const std::string& tag);
    EntityVecTwo& getEntities();
    EntityVecTwo& getEntities(const std::string& tag);
    EntityMapTwo& getEntityMap();

    // Update entities in m_toAddEntites
    void update();
    
    size_t getTotalCreatedEntities();
    size_t getTotalAliveEntities();
    size_t getTotalWaitingEntities();
};

}