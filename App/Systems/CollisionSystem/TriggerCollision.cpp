//
// Created by Noki, Timothé Van Deputte on 20/04/2016.
//

#include "TriggerCollision.hpp"
#include "BoxColliderComponent.hpp"

TriggerCollision::TriggerCollision(BoxColliderComponent *trigger, BoxColliderComponent *collider) : trigger(trigger),
                                                                                                    collider(collider) {
}

TriggerCollision::~TriggerCollision() {

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