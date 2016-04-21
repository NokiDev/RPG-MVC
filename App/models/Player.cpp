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
#include <App/Components/Transform.hpp>
#include <App/Components/Physics.hpp>


Player::Player(IController *boss) : Entity(boss) {

    Transform *t = getComponent<Transform>();
    t->direction = sf::Vector2i(1, 0);
    name = "Player";
    size = sf::Vector2u(64, 64);
    addComponent(new BoxColliderComponent(this, size));///Allow to collide with things !
    addComponent(new Physics(this));///Allow to move
    //NeedToChangeThis to script
    addScript(new PlayerScript(this));

    addComponent(new PlayerEventsHandler(this));

    addScript(new Damageable(this, 20.f));

    layer = "Player";

    spriteRenderer = boss->newSpriteRenderer("player.png");
}

Player::~Player() {
    removeComponent<Damageable>();

    removeComponent<PlayerEventsHandler>();

    removeComponent<PlayerScript>();


    removeComponent<Physics>();
    removeComponent<BoxColliderComponent>();

    boss->delSpriteRenderer(spriteRenderer);
}

void Player::update(sf::Time deltaTime) {
    Transform *t = getComponent<Transform>();
    spriteRenderer->updatePosition(t->position);
}
