//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//


#include <App/Systems/CollisionSystem/CollisionSystem.hpp>
#include <App/Systems/CollisionSystem/IDetectionHelper.hpp>
#include "BoxColliderComponent.hpp"
#include "Entity.hpp"

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
    if(owner->getVelocity().x != 0 || owner->getVelocity().y != 0);
        CollisionSystem::collisionSystem->addMovingBoxCollider(this);
    box.left = pos.x + owner->getVelocity().x + offset.x;
    box.top = pos.y + owner->getVelocity().y + offset.y;

}

sf::FloatRect BoxColliderComponent::getNextBox()const {
    sf::Vector2f & vel = owner->getVelocity();
    return sf::FloatRect(box.left + vel.x, box.top + vel.y, box.width, box.height);
}

void BoxColliderComponent::onCollision(BoxColliderComponent & collider) {

}

void BoxColliderComponent::onCollision(sf::FloatRect box) {
    ///OnCollision with Window for example
    float x=owner->getPosition().x;
    float y=owner->getPosition().y;

    if(x < 0){
        x =0;
    }
    else if (x + size.x> box.width){
        x = box.width- size.x;
    }
    if(y < 0){
        y =0;
    }
    else if(y +size.y> box.height){
        y = box.height - size.y;
    }

    owner->setPosition(x,y);
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
