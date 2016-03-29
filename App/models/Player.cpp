//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include "Player.hpp"
#include "Ressources.hpp"


Player::Player() : Entity() {
    position = sf::Vector2f(0.f, 0.f);
    velocity = sf::Vector2f(0.f, 0.f);
    speed = 250;
    name = "Player";
    sf::Texture &text = Ressources::Load("player.png");
    sprite.setTexture(text);

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

    sprite.setPosition(position);

}


void Player::onCollision() {

}

void Player::render(IView& view) {
    view.draw(sprite);
}
