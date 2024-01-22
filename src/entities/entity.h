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
    ~Entity();

    void kill();
public:
    const std::string& tag();
    friend class EntityManager;
};

}