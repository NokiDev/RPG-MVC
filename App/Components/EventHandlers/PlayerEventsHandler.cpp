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
    if(owner->getBoss()->isKeyPressed(sf::Keyboard::Space)){
        if(timer >= player->getAttackSpeed())
        {
            timer = 0.f;
            IngameController* ingameController = dynamic_cast<IngameController*> (owner->getBoss());
            Laser* laser = new Laser(owner->getBoss());
            ingameController->instantiate(laser, owner->getPosition() + sf::Vector2f(owner->getSize().x, owner->getSize().y/2), sf::Vector2f(1.0f,0.f));

        }
    }
    owner->setVelocity(sf::Vector2f(0.f,0.f));
    float x=0,y=0;
    if (owner->getBoss()->isKeyPressed(sf::Keyboard::Left)) {
        x= -1.0f;
    }
    else if (owner->getBoss()->isKeyPressed(sf::Keyboard::Right)) {
        x = 1.0f;
    }
    if (owner->getBoss()->isKeyPressed(sf::Keyboard::Up)) {
        y = -1.0f;
    }
    else if (owner->getBoss()->isKeyPressed(sf::Keyboard::Down)) {
        y = 1.0f;
    }
    owner->setDirection(sf::Vector2f(x,y));
}
