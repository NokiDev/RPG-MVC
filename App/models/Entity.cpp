//
// Created by Noki, Timothé Van Deputte on 16/02/2016.
//

#include "Entity.hpp"


int Entity::nextId = 0;

void Entity::setDirection(sf::Vector2f dir) {
    direction = dir;
}

sf::Vector2f Entity::getDirection() {
    return direction;
}
