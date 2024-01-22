#include "entity.h"

namespace em {

Entity::Entity() {}

Entity::Entity(const std::string & tag, const size_t & id) : m_tag(tag), m_id(id) {}

Entity::~Entity() {}

const std::string & Entity::tag() {
    return m_tag;
}

void Entity::kill() {
    m_alive = false;
}

}
