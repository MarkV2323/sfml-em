#pragma once

#include <SFML/System/Vector2.hpp>

namespace ecs {

class BoundingBox
{
private:
    BoundingBox() {};
    sf::Vector2f boundingBox;
public:
    BoundingBox(sf::Vector2f bb);
    BoundingBox(float w, float h);
    ~BoundingBox();
    
    sf::Vector2f& getBoundingBox();
    bool setBoundingBox(sf::Vector2f& bb);
};

}