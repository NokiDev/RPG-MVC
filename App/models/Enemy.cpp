//
// Created by bluedragonfly on 4/17/16.
//
#include <App/Components/Scripts/Damageable.hpp>
#include <App/Components/Scripts/EnemyScript.hpp>
#include "Enemy.hpp"

#include "IController.hpp"
#include "BoxColliderComponent.hpp"


Enemy::Enemy(IController *boss) : Entity(boss) {
    position = sf::Vector2f(1000.f, 1000.f);
    direction = sf::Vector2f(-1.f, 0.f);//facing OUEST
    velocity = sf::Vector2f(-1.f, 0.f);
    size = sf::Vector2u(64, 64);

    addComponent(new BoxColliderComponent(this, size));
    addComponent(new EnemyScript(this));
    addComponent(new Damageable(this, 10.f));

    spriteRenderer = boss->newSpriteRenderer("enemy.png");
}

Enemy::~Enemy() {
    removeComponent<BoxColliderComponent>();
    removeComponent<EnemyScript>();
    removeComponent<Damageable>();
    delete spriteRenderer;
}

void Enemy::onCollision(BoxColliderComponent *collider) {

}

void Enemy::update(sf::Time deltaTime) {

}

void Enemy::physicsUpdate() {
    position += velocity;
    spriteRenderer->updatePosition(position);
}
