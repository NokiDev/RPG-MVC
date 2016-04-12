//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include "Player.hpp"
#include "Ressources.hpp"
#include <App/Components/BoxColliderComponent.hpp>
#include <View.hpp>
#include <App/controllers/IController.hpp>


Player::Player(IController* boss) : Entity(), boss(boss){
    position = sf::Vector2f(0.f, 0.f);
    velocity = sf::Vector2f(0.f, 0.f);
    size = sf::Vector2u(64,64);;
    speed = 250;
    name = "Player";
    addComponent(typeid(BoxColliderComponent).name(), new BoxColliderComponent(this, size));
    BoxColliderComponent* component = getComponent<BoxColliderComponent>();
    spriteRenderer = boss->newSpriteRenderer("player.png");
}

Player::~Player() {

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
    spriteRenderer->updatePosition(position);
}


void Player::onCollision() {

}
