//
// Created by bluedragonfly on 4/14/16.
//

#ifndef RPG_MVC_EVENTHANDLERCOMPONENT_HPP
#define RPG_MVC_EVENTHANDLERCOMPONENT_HPP


#include <SFML/Window/Event.hpp>
#include "Component.hpp"


/*
 * @brief HandleEvents like window, keyboard, mouse events .. etc..
 *
 */
class EventHandlerComponent : public Component {

public :
    /**
     * @brief default ctor
     * param Entity owner of the component
    **/
    EventHandlerComponent(Entity *owner);

    /**
     * @brief dtor
     */
    ~EventHandlerComponent();


    /**
     * @brief handle events from view
     * @param sf::Event event event, received from ViewSide
     **/
    virtual void handleEvents(sf::Event) = 0;

    /**
     * @brief update, use for get Key state (pressed or not), and do the correct behaviour
     * @param sf::Time deltaTime time between two frames
     **/
    virtual void update(sf::Time deltaTime) = 0;

protected:
};


#endif //RPG_MVC_EVENTHANDLERCOMPONENT_HPP
