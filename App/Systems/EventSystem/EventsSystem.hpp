//
// Created by bluedragonfly on 4/14/16.
//

#ifndef RPG_MVC_INPUTSYSTEM_HPP
#define RPG_MVC_INPUTSYSTEM_HPP

#include <set>
#include <App/Components/EventHandlerComponent.hpp>

/**
 * @brief Regroup all eventsHandler components in the system, that may update them
 **/
class EventsSystem {
public :
    /**
     * @brief static reference to scriptSystem
     **/
    static EventsSystem *eventsSystem;

    /**
     * @brief default ctor
     **/
    EventsSystem();

    /**
     * @brief dtor
     **/
    ~EventsSystem();

    /**
     * @brief add a new component in the system
     * @param component to add
     **/
    void addEventHandler(EventHandlerComponent *eventHandler);

    /**
     * @brief remove component in the system
     * @param component to remove
     **/
    void delEventHandler(EventHandlerComponent *eventHandler);

    /**
     * @brief handleEvents for all components
     * @param sf::Event event to handle
     **/
    void handleEvents(sf::Event event);

    /**
     * @brief update components each frames
     * @param sf::Time deltaTime, time between two frames
     **/
    void update(sf::Time deltaTime);

private:
    std::set<EventHandlerComponent *> eventHandlers;
};


#endif //RPG_MVC_INPUTSYSTEM_HPP
