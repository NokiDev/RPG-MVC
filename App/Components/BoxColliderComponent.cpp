//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//


#include <App/Systems/CollisionSystem/CollisionSystem.hpp>
#include "BoxColliderComponent.hpp"

BoxColliderComponent::BoxColliderComponent(Entity *owner, sf::Vector2u size, bool isTrigger, sf::Vector2f offset) :
        offset(offset),
        size(size),
        trigger(trigger),
        moving(false) {
    this->owner = owner;
    sf::Vector2f pos = owner->getPosition();
    box = sf::FloatRect(pos.x + offset.x, pos.y + offset.y, size.x, size.y);
    CollisionSystem::collisionSystem->addBoxCollider(this);
}

BoxColliderComponent::~BoxColliderComponent() {
    CollisionSystem::collisionSystem->delBoxCollider(this);
}

void BoxColliderComponent::update(sf::Time deltaTime) {
    sf::Vector2f pos = owner->getPosition();
    box.left = pos.x + offset.x;
    box.top = pos.y + offset.y;
}

sf::FloatRect BoxColliderComponent::getNextBox()const {
    sf::Vector2f vel(0.0f,0.0f);
    //sf::Vector2f vel = owner->velocity;
    return sf::FloatRect(box.left + vel.x, box.top + vel.y, box.width, box.height);
}

void BoxColliderComponent::onCollision(BoxColliderComponent & collider) {

}

void BoxColliderComponent::onTriggerEnter(TriggerCollision& collision) {

}

void BoxColliderComponent::onTriggerStay(TriggerCollision & collision) {

}

void BoxColliderComponent::onTriggerExit(TriggerCollision & collision) {

}

sf::FloatRect BoxColliderComponent::getBox()const {
    return box;
}

sf::Vector2u BoxColliderComponent::getSize()const {
    return size;
}

sf::Vector2f BoxColliderComponent::getOffset()const {
    return offset;
}

bool BoxColliderComponent::isMoving()const {
    return trigger;
}

bool BoxColliderComponent::isTrigger()const {
    return moving;
}
