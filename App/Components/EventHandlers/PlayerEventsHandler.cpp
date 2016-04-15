//
// Created by bluedragonfly on 4/15/16.
//

#include <App/models/Laser.hpp>
#include <App/controllers/IngameController.hpp>
#include "PlayerEventsHandler.hpp"

PlayerEventsHandler::PlayerEventsHandler(Entity *owner) : EventHandlerComponent(owner) {

}

PlayerEventsHandler::~PlayerEventsHandler() {

}

void PlayerEventsHandler::handleEvents(sf::Event event) {
    if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Return){
            IngameController* ingameController = dynamic_cast<IngameController*> (owner->getBoss());
            ingameController->instantiate(new Laser(owner->getBoss()), owner->getPosition(), owner->getDirection());
            std::cout<<"RETURN PRESSED"<<std::endl;
        }
    }
    else if(event.type == sf::Event::KeyReleased){
    }
}

void PlayerEventsHandler::update(sf::Time deltaTime) {

    if(owner->getBoss()->isKeyPressed(sf::Keyboard::Return)){
        IngameController* ingameController = dynamic_cast<IngameController*> (owner->getBoss());
        ingameController->instantiate(new Laser(owner->getBoss()), owner->getPosition(), owner->getDirection());
        std::cout<<"RETURN PRESSED"<<std::endl;
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
