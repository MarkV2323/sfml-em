#include "transform.h"

namespace ecs {
    Transform::Transform(sf::Vector2f p, sf::Vector2f v) : position(p), velocity(v) {}
    Transform::Transform(float x, float y, float vx, float vy) : position(sf::Vector2f(x, y)), velocity(sf::Vector2f(vx, vy)) {}
    Transform::~Transform() {}

    sf::Vector2f& Transform::getPosition() {
        return position;
    }

    bool Transform::setPosition(sf::Vector2f& p) {
        position = p;
        return true;
    }

    sf::Vector2f& Transform::getVelocity() {
        return velocity;
    }

    bool Transform::setVelocity(sf::Vector2f& v) {
        velocity = v;
        return true;
    }
}
