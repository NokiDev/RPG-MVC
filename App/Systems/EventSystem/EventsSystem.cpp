//
// Created by bluedragonfly on 4/14/16.
//

#include "EventsSystem.hpp"
#include <iostream>

EventsSystem* EventsSystem::eventsSystem;

EventsSystem::EventsSystem() {
    if(eventsSystem == nullptr){
        eventsSystem = this;
    }
    else{
        std::cerr<<"WARNING Singleton - Constructor called Twice, Fix This !"<<std::endl;
    }
}

EventsSystem::~EventsSystem() {

}

void EventsSystem::handleEvents(sf::Event event) {
    for(auto eventHandler : eventHandlers){
        eventHandler->handleEvents(event);
    }
}

void EventsSystem::addEventHandler(EventHandlerComponent *eventHandler) {
    eventHandlers.insert(eventHandler);
}

void EventsSystem::delEventHandler(EventHandlerComponent *eventHandler) {
    eventHandlers.erase(eventHandler);
}
