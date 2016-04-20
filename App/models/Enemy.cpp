//
// Created by bluedragonfly on 4/17/16.
//
#include <App/Components/Scripts/Damageable.hpp>
#include <App/Components/Scripts/EnemyScript.hpp>
#include <App/Components/Transform.hpp>
#include <App/Components/Physics.hpp>
#include "Enemy.hpp"

#include "IController.hpp"
#include "BoxColliderComponent.hpp"


Enemy::Enemy(IController *boss) : Entity(boss) {
    Transform* t = getComponent<Transform>();
    t->position = sf::Vector2f(650.f,150.f);
    t->direction = sf::Vector2i(-1, 0);//facing OUEST
    size = sf::Vector2u(64,64);
    addComponent(new BoxColliderComponent(this, size));
    addComponent(new Physics(this));
    addScript(new EnemyScript(this));
    addScript(new Damageable(this, 20.f));

    layer = "Enemy";

    ///Need to be A Component
    spriteRenderer = boss->newSpriteRenderer("enemy.png");
}

Enemy::~Enemy() {
    removeScript<Damageable>();
    removeScript<EnemyScript>();
    removeComponent<Physics>();
    removeComponent<BoxColliderComponent>();
    delete spriteRenderer;
}

void Enemy::update(sf::Time deltaTime) {
    Transform* t = getComponent<Transform>();
    spriteRenderer->updatePosition(t->position);
}
