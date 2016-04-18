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
#include <App/Components/Scripts/Damageable.hpp>


Player::Player(IController* boss) : Entity(boss){
    position = sf::Vector2f(0.f, 0.f);
    velocity = sf::Vector2f(0.f, 0.f);
    direction = sf::Vector2f(1.f,0.f);//Facing est
    size = sf::Vector2u(64,64);
    name = "Player";
    speed = 350;
    addComponent(new BoxColliderComponent(this, size));
    addComponent(new PlayerScript(this));
    addComponent(new Damageable(this, 100.f));
    addComponent(new PlayerEventsHandler(this));

    spriteRenderer = boss->newSpriteRenderer("player.png");
}

Player::~Player() {
    removeComponent<PlayerEventsHandler>();
    removeComponent<BoxColliderComponent>();
    removeComponent<Damageable>();
    boss->delSpriteRenderer(spriteRenderer);
}


void Player::update(sf::Time deltaTime) {
    float modifier  = 1.f;
    if(direction.x >0)
        modifier = 0.5;
    velocity.x= speed * deltaTime.asSeconds() *direction.x * modifier;

    if (direction.y != 0)
        modifier = 0.7;
    velocity.y= speed * deltaTime.asSeconds()  * direction.y * modifier;
}

void Player::physicsUpdate() {
    position += velocity;
    spriteRenderer->updatePosition(position);
}


void Player::onCollision(BoxColliderComponent* collider) {

}