//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#include "BoxColliderComponent.hpp"

BoxColliderComponent::BoxColliderComponent(Entity *owner, sf::Vector2u size, bool isTrigger, sf::Vector2f offset) :
        offset(offset),
        size(size),
        isTrigger(isTrigger),
        isMoving(false) {
    this->owner = owner;
    sf::Vector2f pos = owner->position;
    box = sf::FloatRect(pos.x + offset.x, pos.y + offset.y, size.x, size.y);
    ///CollisionSystem->AddBoxCollider(this);
}

BoxColliderComponent::~BoxColliderComponent() {
    //CollisionSystem->DelBoxCollider(this);
}

void BoxColliderComponent::update(sf::Time deltaTime) {
    sf::Vector2f pos = owner->position;
    box.left = pos.x + offset.x;
    box.top = pos.y + offset.y;
}

sf::FloatRect BoxColliderComponent::getNextBox() {
    sf::Vector2f vel(0.0f,0.0f);
    //sf::Vector2f vel = owner->velocity;
    return sf::FloatRect(box.left + vel.x, box.top + vel.y, box.width, box.height);
}
