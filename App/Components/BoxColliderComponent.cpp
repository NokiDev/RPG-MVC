//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//


#include <App/Systems/CollisionSystem/CollisionSystem.hpp>
#include <App/Systems/CollisionSystem/IDetectionHelper.hpp>
#include "BoxColliderComponent.hpp"
#include "Entity.hpp"
#include "Transform.hpp"
#include "Physics.hpp"

BoxColliderComponent::BoxColliderComponent(Entity *owner, sf::Vector2u size, bool isTrigger, sf::Vector2f offset) :
        offset(offset),
        size(size),
        trigger(isTrigger),
        moving(false) {
    this->owner = owner;
    sf::Vector2f pos = owner->getComponent<Transform>()->position;
    box = sf::FloatRect(pos.x + offset.x, pos.y + offset.y, size.x, size.y);
    CollisionSystem::collisionSystem->addBoxCollider(this);
}

BoxColliderComponent::~BoxColliderComponent() {
    CollisionSystem::collisionSystem->delBoxCollider(this);
}

void BoxColliderComponent::update(sf::Time deltaTime) {
    Transform *t = owner->getComponent<Transform>();
    box.left = t->position.x;
    box.top = t->position.y;

}

sf::FloatRect BoxColliderComponent::getNextBox() const {
    Physics *p = owner->getComponent<Physics>();
    return sf::FloatRect(box.left + p->getVelocity().x, box.top + p->getVelocity().y, box.width, box.height);
}

void BoxColliderComponent::onCollision(BoxColliderComponent *collider) {
    Entity::OnCollision(owner, collider);

}

void BoxColliderComponent::onCollision(sf::FloatRect box) {
    ///OnCollision with Window for example
    Transform *t = owner->getComponent<Transform>();

    float x = t->position.x;
    float y = t->position.y;

    if (x < 0) {
        x = 0;
    }
    else if (x + size.x > box.width) {
        x = box.width - size.x;
    }
    if (y < 0) {
        y = 0;
    }
    else if (y + size.y > box.height) {
        y = box.height - size.y;
    }

    t->position = sf::Vector2f(x, y);
}

void BoxColliderComponent::onTriggerEnter(TriggerCollision *collision) {
    Entity::OnTriggerEnter(owner, collision);
}

void BoxColliderComponent::onTriggerStay(TriggerCollision *collision) {
    Entity::OnTriggerStay(owner, collision);
}

void BoxColliderComponent::onTriggerExit(TriggerCollision *collision) {
    Entity::OnTriggerExit(owner, collision);
}

sf::FloatRect BoxColliderComponent::getBox() const {
    return box;
}

sf::Vector2u BoxColliderComponent::getSize() const {
    return size;
}

sf::Vector2f BoxColliderComponent::getOffset() const {
    return offset;
}

bool BoxColliderComponent::isMoving() const {
    return moving;
}

bool BoxColliderComponent::isTrigger() const {
    return trigger;
}
