//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#include <iostream>
#include <SFML/Window/Keyboard.hpp>
#include "Player.hpp"
#include "Ressources.hpp"
#include <Components/RenderComponent.hpp>
#include <App/Components/BoxColliderComponent.hpp>
#include <View.hpp>


Player::Player() : Entity() {
    position = sf::Vector2f(0.f, 0.f);
    velocity = sf::Vector2f(0.f, 0.f);
    speed = 250;
    name = "Player";
    sf::Texture &text = Ressources::Load("player.png");
    sprite.setTexture(text);
    addComponent(typeid(BoxColliderComponent).name(), new BoxColliderComponent(this, sf::Vector2u(64,64)));
    BoxColliderComponent* component = getComponent<BoxColliderComponent>();

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

    float wallRight = 720 - getSpriteSize().x;
    float wallBottom = 480 - getSpriteSize().y;
    if (position.x < 0)
        position.x = 0;
    else if (position.x > wallRight)
        position.x = wallRight;
    if (position.y < 0)
        position.y = 0;
    else if (position.y > wallBottom)
        position.y = wallBottom;
}


void Player::onCollision() {

}

void Player::render(View & view) {
    sprite.setPosition(position);
    view.draw(sprite);
}

sf::Vector2f Player::getSpriteSize() {
    float x = sprite.getGlobalBounds().width;
    float y = sprite.getGlobalBounds().height;
    return sf::Vector2<float>(x, y);
}
