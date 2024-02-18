#pragma once

#include <SFML/System/Vector2.hpp>

namespace ecs {
/**
 * Transform contains information about position and veloctiy.
*/
class Transform
{
private:
    Transform() {};
    sf::Vector2f position;
    sf::Vector2f velocity;
public:
    Transform(sf::Vector2f p, sf::Vector2f v);
    Transform(float x, float y, float vx, float vy);
    ~Transform();
    
    sf::Vector2f& getPosition();
    bool setPosition(sf::Vector2f& p);

    sf::Vector2f& getVelocity();
    bool setVelocity(sf::Vector2f& v);
};

}