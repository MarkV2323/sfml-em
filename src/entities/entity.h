#pragma once

#include <string>

#include "components/transform.h"
#include "components/shape.h"
#include "components/boundingBox.h"

namespace em {

class Entity 
{
private:
    const size_t m_id {0};
    const std::string m_tag {"Default"};
    bool m_alive {true};

    // components for Entity

    ecs::Shape m_shape{2, sf::Vector2f{10, 10}};
    ecs::Transform m_transform{10, 10, 1, 1};
    ecs::BoundingBox m_bb{4, 4};

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

    // Return const circleShape
    const sf::CircleShape& getCircleShape();
    
    // Return Entity's position
    sf::Vector2f& getPos();

    // Return Entity's velocity
    sf::Vector2f& getVel();

    // Update Entity's position
    void setPos(sf::Vector2f& p);

    // Update Entity's velocity
    void setVel(sf::Vector2f& v);

    // Return Entity's boundBox Vector
    sf::Vector2f& getBounds();
};

}