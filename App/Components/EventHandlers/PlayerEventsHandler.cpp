//
// Created by bluedragonfly on 4/15/16.
//

#include <App/models/Laser.hpp>
#include <App/controllers/IngameController.hpp>
#include "PlayerEventsHandler.hpp"
#include "Entity.hpp"


PlayerEventsHandler::PlayerEventsHandler(Entity *owner) : EventHandlerComponent(owner), timer(0.f) {
    player = owner->getScript<PlayerScript>();
    transform = owner->getComponent<Transform>();
    physic = owner->getComponent<Physics>();
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
            Laser* laser = new Laser(owner->getBoss(), "Enemy");
            Laser* laser2 = new Laser(owner->getBoss(), "Enemy");
            ingameController->instantiate(laser, transform->position + sf::Vector2f(owner->getSize().x, owner->getSize().y/4), sf::Vector2i(1,0 ));

            ingameController->instantiate(laser2, transform->position + sf::Vector2f(owner->getSize().x, owner->getSize().y/4 + owner->getSize().y/2), sf::Vector2i(1,0 ));
        }
    }
    float x=0,y=0;
    int speed = player->getSpeed();
    if (owner->getBoss()->isKeyPressed(sf::Keyboard::Left)) {
        x=-speed*deltaTime.asSeconds()  * 0.9f;
    }
    else if (owner->getBoss()->isKeyPressed(sf::Keyboard::Right)) {
        x=speed*deltaTime.asSeconds()  * 0.5f;
    }
    if (owner->getBoss()->isKeyPressed(sf::Keyboard::Up)) {
        y=-speed*deltaTime.asSeconds() * 0.7f;
    }
    else if (owner->getBoss()->isKeyPressed(sf::Keyboard::Down)) {
        y=speed*deltaTime.asSeconds() * 0.7f;
    }
    physic->setVelocity(sf::Vector2f(x,y));
}
