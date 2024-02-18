#pragma once

#include <string>

namespace em {

class Entity 
{
private:
    const size_t m_id = 0;
    const std::string m_tag = "Default";
    bool m_alive = true;

    Entity();
    Entity(const std::string& tag, const size_t& id);
public:
    friend class EntityManager;
    friend class EntityManagerTwo;

    // Public decontructor
    ~Entity();
    
    // Return tag of this entity
    const std::string& tag();

    // Return id of this entity
    const size_t& id();

    // Set alive to false for this entity
    void kill();
};

}