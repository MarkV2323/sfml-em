#include "boundingBox.h"

namespace ecs {
    BoundingBox::BoundingBox(sf::Vector2f bb) : boundingBox(bb) {}

    BoundingBox::BoundingBox(float w, float h) : boundingBox(sf::Vector2f(w, h)) {}

    BoundingBox::~BoundingBox() {}

    sf::Vector2f& BoundingBox::getBoundingBoxDimension() {
        return boundingBox;
    }

    bool BoundingBox::setBoundingBox(sf::Vector2f &bb) {
        boundingBox = bb;
        return true;
    }
}
