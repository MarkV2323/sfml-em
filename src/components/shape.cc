#include "shape.h"

namespace ecs {
    Shape::Shape(float r, sf::Vector2f& p) : circle(sf::CircleShape(r)) {
        circle.setPosition(p);
        circle.setFillColor(sf::Color::White);
    }
    Shape::~Shape() {}

    sf::CircleShape& Shape::getCircle() {
        return circle;
    }
    
    void Shape::setPosition(sf::Vector2f &p) {
        circle.setPosition(p);
    }

    void Shape::setColor(sf::Color & c) {
        circle.setFillColor(c);
    }

}
