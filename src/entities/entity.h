#pragma once

namespace em {

class Entity 
{
private:
    const size_t m_id = 0;
    const std::string m_tag = "Default";
    bool m_alive = true;
public:
    Entity();
    ~Entity();
};

}