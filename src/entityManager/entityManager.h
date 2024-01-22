#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "entities/entity.h"

namespace em {

typedef std::vector<Entity*> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;

class EntityManager
{
private:
    EntityVec m_entities;
    EntityVec m_toAddEntites;
    EntityMap m_entityMap;
    size_t m_totalEntities = 0;
public:
    EntityManager();
    ~EntityManager();

    Entity* addEntity(const std::string& tag);
    void removeEntity(Entity& e);

    EntityVec& getEntities();
    EntityVec& getEntities(const std::string& tag);
    
    // Update entities in m_toAddEntites
    void update();
    
    size_t getTotalCreatedEntities();
    size_t getTotalAliveEntities();
    size_t getTotalWaitingEntities();
};

}