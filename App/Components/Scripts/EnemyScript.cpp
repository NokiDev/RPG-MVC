//
// Created by bluedragonfly on 4/18/16.
//

#include <App/App.hpp>
#include <App/models/Laser.hpp>
#include <App/Components/Transform.hpp>
#include "EnemyScript.hpp"
#include "Damageable.hpp"
#include "Physics.hpp"

EnemyScript::EnemyScript(Entity *owner) : ScriptComponent(owner) {
    physics = owner->getComponent<Physics>();
    speed = 25;
    attackSpeed = 1.5f;
    timer = 0.f;
}

EnemyScript::~EnemyScript() {

}


void EnemyScript::update(sf::Time deltaTime) {
    Damageable *damageableScript = owner->getScript<Damageable>();
    if (damageableScript != nullptr) {
        if (damageableScript->isDead()) {
            controller->destroy(owner);
        }
    }

    timer += deltaTime.asSeconds();
    if (timer >= attackSpeed) {
        timer = 0.f;
        Transform *t = owner->getComponent<Transform>();
        sf::Vector2f pos = sf::Vector2f(t->position.x, t->position.y + owner->getSize().y / 2);
        controller->instantiate(new Laser(controller, "Player"), pos, sf::Vector2i(-1, 0));
    }
}

void EnemyScript::physicsUpdate() {
    float x = -speed * App::get()->DeltaTime().asSeconds();

    physics->setVelocityX(x);
}

int EnemyScript::getSpeed() {
    return speed;
}
