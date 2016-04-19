//
// Created by bluedragonfly on 3/22/16.
//

#include <App/models/Entity.hpp>
#include <SFML/System.hpp>
#include "Transform.hpp"

Transform::Transform(Entity *owner, sf::Vector2f position, int z,  sf::Vector2i direction, sf::Vector2f rotation, sf::Vector2f scale):
        position(position), z(z), direction(direction),
        rotation(rotation),
        scale(scale){
    this->owner= owner;

}

Transform::~Transform() {

}

void Transform::move(float x, float y) {
    position.x += x;
    position.y += y;
}
