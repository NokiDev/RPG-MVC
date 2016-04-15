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
#include <App/Components/EventHandlers/PlayerEventsHandler.hpp>


Player::Player(IController* boss) : Entity(){
    this->boss = boss;
    position = sf::Vector2f(0.f, 0.f);
    velocity = sf::Vector2f(0.f, 0.f);
    direction = sf::Vector2f(0.f,0.f);
    size = sf::Vector2u(64,64);
    speed = 350;
    name = "Player";
    eventHandler = new PlayerEventsHandler(this);
    boxCollider = new BoxColliderComponent(this, size);
    spriteRenderer = boss->newSpriteRenderer("player.png");
}

Player::~Player() {

}


void Player::update(sf::Time deltaTime) {
    eventHandler->update(deltaTime);
    boxCollider->update(deltaTime);

}

void Player::physicsUpdate() {
    position += velocity;
    spriteRenderer->updatePosition(position);
}


void Player::onCollision(BoxColliderComponent* collider) {

}
