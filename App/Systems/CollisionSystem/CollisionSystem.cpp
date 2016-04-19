//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#include <iostream>
#include <App/views/WindowManager.hpp>
#include <App/Components/Transform.hpp>
#include "CollisionSystem.hpp"
#include "IDetectionHelper.hpp"
#include "ICollisionHelper.hpp"
#include "Entity.hpp"

CollisionSystem *CollisionSystem::collisionSystem;



CollisionSystem::CollisionSystem() {
    if(CollisionSystem::collisionSystem != nullptr)
    {
        std::cerr<<"WARNING !! Collision System already Exist !"<<std::endl;
        delete this;
    }
    else
        CollisionSystem::collisionSystem = this;
}

CollisionSystem::~CollisionSystem() {

}

void CollisionSystem::addBoxCollider(BoxColliderComponent *boxCollider) {
    boxColliders.insert(boxCollider);
}

void CollisionSystem::delBoxCollider(BoxColliderComponent *boxCollider) {
    boxColliders.erase(boxCollider);
    if(boxCollider->isTrigger()){
        for(auto trigger : triggerCollisions){
            if(trigger->getTrigger() == boxCollider){
                trigger->getTrigger()->onTriggerExit(trigger);
                triggerCollisions.erase(trigger);
            }
        }
    }
}

void CollisionSystem::addMovingBoxCollider(BoxColliderComponent *boxCollider) {
    movingColliders.insert(boxCollider);
}

void CollisionSystem::checkCollisions() {
    for(BoxColliderComponent* collider : movingColliders)
    {
        for(BoxColliderComponent* other : boxColliders)
        {
            if((collider != other) && (!collider->isTrigger() || !other->isTrigger()))
            {
                if(IDetectionHelper::DetectIsNear(3, collider->getNextBox(), other->getBox()))
                {
                    if(ICollisionHelper::AABBCollision(collider->getNextBox(), other->getBox()))
                    {
                        if(collider->isTrigger())
                        {
                            TriggerCollision* collision = new TriggerCollision(collider, other);
                            triggerCollisions.insert(collision);
                            //collider->onTriggerEnter(collision);
                            //other->onTriggerEnter(collision);
                        }
                        else if (other->isTrigger())
                        {
                            TriggerCollision* collision = new TriggerCollision(other, collider);
                            triggerCollisions.insert(collision);
                            //collider->onTriggerEnter(collision);
                            //other->onTriggerEnter(collision);
                        }
                        else
                        {
                            other->onCollision(collider);
                            //collider->onCollision(other);
                        }
                    }
                }
            }
        }
    }
    for(TriggerCollision* collision : triggerCollisions)
    {
        if(collision->isCollide())
        {
            Transform* t = collision->getCollider()->getOwner().getComponent<Transform>();
            if(!ICollisionHelper::NotAABBCollision(t->position, collision->getTrigger()->getBox(), collision->getCollider()->getBox()))
            {
                collision->getTrigger()->onTriggerStay(collision);
            }
            else
            {
                //collision->getTrigger()->onTriggerExiting(collision);
            }
        }
        else
        {
            collision->getTrigger()->onTriggerExit(collision);
            triggerCollisions.erase(collision);
        }
    }
    for(BoxColliderComponent* collider : movingColliders)
    {
        sf::Vector2u winSize = WindowManager::get()->Window().getSize();
        sf::FloatRect winBox = sf::FloatRect(0,0,winSize.x, winSize.y);
        Transform * t = collider->getOwner().getComponent<Transform>();
        if(!ICollisionHelper::NotAABBCollision(t->position,winBox, collider->getBox()));
        {
            collider->onCollision(winBox);
        }
    }
}

TriggerCollision::TriggerCollision(BoxColliderComponent *trigger, BoxColliderComponent *collider) {

}

bool TriggerCollision::collExist(BoxColliderComponent *trigger, BoxColliderComponent *collider) {
    return false;
}

bool TriggerCollision::isCollide() {
    return false;
}

BoxColliderComponent *TriggerCollision::getTrigger() {
    return trigger;
}

BoxColliderComponent *TriggerCollision::getCollider() {
    return collider;
}

void CollisionSystem::updateComponents(sf::Time deltaTime) {
    for(auto collider : boxColliders){
        collider->update(deltaTime);
    }
    movingColliders.clear();
}
