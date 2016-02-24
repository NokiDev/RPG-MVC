//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#include <App/Components/RenderComponent.hpp>
#include <iostream>
#include "Player.hpp"


Player::Player() : Entity() {
    render = new RenderComponent(this, "player");
    position = sf::Vector2f(0.f, 0.f);
    velocity = sf::Vector2f(0.f, 0.f);
    speed = 250;
    name = "Player";
}

Player::~Player() {
    delete render;
}


void Player::update(sf::Time deltaTime) {
    velocity = sf::Vector2f(0.f,0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity.x -= speed * deltaTime.asSeconds();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity.x += speed * deltaTime.asSeconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        velocity.y -= speed * deltaTime.asSeconds();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        velocity.y += speed * deltaTime.asSeconds();
    }
}

void Player::physicsUpdate() {
    position += velocity;
}


void Player::onCollision() {

}
