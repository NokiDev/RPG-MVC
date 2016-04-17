//
// Created by bluedragonfly on 4/14/16.
//

#ifndef RPG_MVC_INPUTSYSTEM_HPP
#define RPG_MVC_INPUTSYSTEM_HPP
#include <set>
#include <App/Components/EventHandlerComponent.hpp>

class EventsSystem {
    public :
        static EventsSystem *eventsSystem;
        EventsSystem();
        ~EventsSystem();
        void addEventHandler(EventHandlerComponent* eventHandler);
        void delEventHandler(EventHandlerComponent* eventHandler);
        void handleEvents(sf::Event event);
        void update(sf::Time deltaTime);
    private:
        std::set<EventHandlerComponent*> eventHandlers;
};


#endif //RPG_MVC_INPUTSYSTEM_HPP
