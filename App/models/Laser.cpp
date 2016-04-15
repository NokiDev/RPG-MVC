//
// Created by bluedragonfly on 4/14/16.
//

#include "Laser.hpp"

Laser::Laser(IController *boss) {
    this->boss = boss;
    position = sf::Vector2f(0.f, 0.f);
    velocity = sf::Vector2f(1.f, 0.f);
    direction = sf::Vector2f(0.f, 0.f);
    size = sf::Vector2u(10, 5);
    speed = 550;
    name = "Laser";

    spriteRenderer = boss->newSpriteRenderer("laser.png");
    boxColliderComponent = new BoxColliderComponent(this, sf::Vector2u(10, 5));

}

Laser::~Laser() {

}

void Laser::update(sf::Time deltaTime) {

}

void Laser::physicsUpdate() {
    position += velocity;
    spriteRenderer->updatePosition(position);
}

void Laser::onCollision(BoxColliderComponent* collider) {

}
