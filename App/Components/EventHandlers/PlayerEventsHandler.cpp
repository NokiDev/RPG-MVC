//
// Created by bluedragonfly on 4/15/16.
//

#include <App/models/Laser.hpp>
#include <App/controllers/IngameController.hpp>
#include "PlayerEventsHandler.hpp"
#include "Entity.hpp"


PlayerEventsHandler::PlayerEventsHandler(Entity *owner) : EventHandlerComponent(owner), timer(0.f) {
    player = owner->getComponent<PlayerScript>();
    if(player == nullptr){
        std::cerr<<"For use this script please attach the PlayerScript Too"<<std::endl;
    }
}

PlayerEventsHandler::~PlayerEventsHandler() {

}

void PlayerEventsHandler::handleEvents(sf::Event event) {
    if(event.type == sf::Event::KeyPressed){

    }
    else if(event.type == sf::Event::KeyReleased){
    }
}

void PlayerEventsHandler::update(sf::Time deltaTime) {
    timer +=deltaTime.asSeconds();
    if(owner->getBoss()->isKeyPressed(sf::Keyboard::Return)){
        if(timer >= player->getAttackSpeed())
        {
            timer = 0.f;
            IngameController* ingameController = dynamic_cast<IngameController*> (owner->getBoss());
            Laser* laser = new Laser(owner->getBoss());
            ingameController->instantiate(laser, owner->getPosition() + sf::Vector2f(owner->getSize().x, owner->getSize().y/2), owner->getDirection());

        }
    }
    owner->setVelocity(sf::Vector2f(0.f,0.f));
    int speed = owner->getSpeed();
    float x=0,y=0;
    if (owner->getBoss()->isKeyPressed(sf::Keyboard::Left)) {
        x -= speed *0.7* deltaTime.asSeconds();
    }
    else if (owner->getBoss()->isKeyPressed(sf::Keyboard::Right)) {
        x += speed * 0.5* deltaTime.asSeconds();
    }
    if (owner->getBoss()->isKeyPressed(sf::Keyboard::Up)) {
        y -= speed *0.7* deltaTime.asSeconds();
    }
    else if (owner->getBoss()->isKeyPressed(sf::Keyboard::Down)) {
        y += speed *0.9* deltaTime.asSeconds();
    }
    owner->setVelocity(sf::Vector2f(x,y));
}
