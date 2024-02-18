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

ecs::Shape& Entity::getShape() {
    return m_shape;
}

ecs::Transform& Entity::getTransform() {
    return m_transform;
}

}
