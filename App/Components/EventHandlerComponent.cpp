//
// Created by bluedragonfly on 4/14/16.
//

#include "EventsSystem.hpp"
#include "EventHandlerComponent.hpp"

EventHandlerComponent::EventHandlerComponent(Entity *owner){
    this->owner = owner;
    EventsSystem::eventsSystem->addEventHandler(this);
}

EventHandlerComponent::~EventHandlerComponent() {
    EventsSystem::eventsSystem->delEventHandler(this);
}

void EventHandlerComponent::handleEvents(sf::Event event) {
    if(event.type == sf::Event::KeyPressed){

    }
    else if(event.type == sf::Event::KeyReleased){

    }
}

void EventHandlerComponent::update(sf::Time deltaTime) {

}
