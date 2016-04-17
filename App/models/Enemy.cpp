//
// Created by bluedragonfly on 4/17/16.
//

#include "Enemy.hpp"

#include "IController.hpp"
#include "BoxColliderComponent.hpp"

Enemy::Enemy(IController *boss) : Entity(boss) {
    position = sf::Vector2f(0.f,0.f);
    direction = sf::Vector2f(-1.f,0.f);//facing OUEST
    velocity = sf::Vector2f(0.f, 0.f);
    size = sf::Vector2u(64,64);

    addComponent(new BoxColliderComponent(this, size));

    //addComponent(new EnnemyScript())

    spriteRenderer = boss->newSpriteRenderer("player.png");

}

Enemy::~Enemy() {

}
