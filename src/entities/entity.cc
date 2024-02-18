#include "entity.h"

namespace em {

Entity::Entity() {}

Entity::Entity(const std::string & tag, const size_t & id) : m_tag(tag), m_id(id) {}

Entity::~Entity() {}

const std::string & Entity::tag() {
    return m_tag;
}

const size_t & Entity::id() {
    return m_id;
}

void Entity::kill() {
    m_alive = false;
}

const sf::CircleShape & Entity::getCircleShape() {
    return m_shape.getCircle();
}

sf::Vector2f & Entity::getPos() {
    return m_transform.getPosition();
}

sf::Vector2f & Entity::getVel() {
    return m_transform.getVelocity();
}

void Entity::setPos(sf::Vector2f & p) {
    m_transform.setPosition(p);
    m_shape.setPosition(p);
}

void Entity::setVel(sf::Vector2f & v) {
    m_transform.setVelocity(v);
}

sf::Vector2f & Entity::getBounds() {
    return m_bb.getBoundingBoxDimension();
}

}
