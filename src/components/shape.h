#pragma once

#include <SFML/Graphics/CircleShape.hpp>

namespace ecs {
/**
 * Shape contains information about a sf::sphere
*/
class Shape
{
private:
    Shape() {};
    sf::CircleShape circle;
public:
    Shape(float r, sf::Vector2f& p);
    ~Shape();

    // Return the internal CircleShape
    sf::CircleShape& getCircle();

    // Update the internal CircleShape position
    void setPosition(sf::Vector2f& p);

    // Update the internal CircleShape fill color
    void setColor(sf::Color& c);
};

}