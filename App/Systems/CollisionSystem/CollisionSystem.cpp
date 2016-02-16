//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#include <iostream>
#include "CollisionSystem.hpp"
#include "IDetectionHelper.hpp"
#include "ICollisionHelper.hpp"

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
            if(!ICollisionHelper::NotAABBCollision(collision->getCollider().getOwner().getPosition(), collision->getTrigger().getBox(), collision->getCollider().getBox()))
            {
                //collision->trigger->onTriggerStay(collision->collider);
            }
            else
            {
                //collision->trigger->onTriggerExiting(collision->collider);
            }
        }
        else
        {
            //collision->trigger->onTriggerExit(collision->collider);
            triggerCollisions.erase(collision);
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

BoxColliderComponent &TriggerCollision::getTrigger() {
    return *trigger;
}

BoxColliderComponent &TriggerCollision::getCollider() {
    return *collider;
}
