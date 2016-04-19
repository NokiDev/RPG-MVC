//
// Created by bluedragonfly on 4/18/16.
//

#include <App/App.hpp>
#include <App/Components/Transform.hpp>
#include <App/Components/Physics.hpp>
#include "LaserScript.hpp"
#include "Damageable.hpp"
#include "CollisionSystem.hpp"

LaserScript::LaserScript(Entity *owner, std::string attackLayer) : ScriptComponent(owner){
    physics = owner->getComponent<Physics>();
    speed = 550;
    this->attackLayer = attackLayer;
}

LaserScript::~LaserScript() {

}


void LaserScript::update(sf::Time deltaTime) {

}

void LaserScript::physicsUpdate() {
    Transform * t = owner->getComponent<Transform>();
    float x = speed * App::get()->DeltaTime().asSeconds()*t->direction.x;
    float y = speed * App::get()->DeltaTime().asSeconds()*t->direction.y;
    physics->setVelocity(sf::Vector2f(x,y));
}

void LaserScript::onCollision(BoxColliderComponent *collision) {
    Damageable* damageScript = collision->getOwner().getScript<Damageable>();
    if(collision->getOwner().getLayer() == attackLayer){
        if(damageScript != nullptr){
            damageScript->takeDamage(1);
            controller->destroy(owner);
        }
    }
}
