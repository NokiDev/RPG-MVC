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


Player::Player(IController* boss) : Entity(boss){
    position = sf::Vector2f(0.f, 0.f);
    velocity = sf::Vector2f(0.f, 0.f);
    direction = sf::Vector2f(0.f,0.f);
    size = sf::Vector2u(64,64);
    name = "Player";
    speed = 350;
    addComponent(new BoxColliderComponent(this, size));
    addComponent(new PlayerScript(this));
    addComponent(new PlayerEventsHandler(this));

    spriteRenderer = boss->newSpriteRenderer("player.png");
}

Player::~Player() {
    removeComponent<PlayerEventsHandler>();
    removeComponent<BoxColliderComponent>();
    boss->delSpriteRenderer(spriteRenderer);
}


void Player::update(sf::Time deltaTime) {
}

void Player::physicsUpdate() {
    position += velocity;
    spriteRenderer->updatePosition(position);
}


void Player::onCollision(BoxColliderComponent* collider) {

}