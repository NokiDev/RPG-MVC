//
// Created by bluedragonfly on 4/15/16.
//

#ifndef RPG_MVC_PLAYEREVENTSHANDLER_HPP
#define RPG_MVC_PLAYEREVENTSHANDLER_HPP


#include <App/models/Entity.hpp>
#include <App/Components/EventHandlerComponent.hpp>
#include <App/Components/Scripts/PlayerScript.hpp>

/**
 * @brief Handles Event for the Player, events are Keyboard, mouse, window event etc...
 *
 **/
class PlayerEventsHandler : public EventHandlerComponent {
public :
    /**
     *  @brief default ctor
     *  @param owner of this component
     **/
    PlayerEventsHandler(Entity *owner);

    /**
     * @brief default dtor
     **/
    ~PlayerEventsHandler();

    /**
     * @brief handle events from view
     * @param sf::Event event event, received from ViewSide
     **/
    virtual void handleEvents(sf::Event event);

    /**
     * @brief update, use for get Key state (pressed or not), and do the correct behaviour
     * @param sf::Time deltaTime time between two frames
     **/
    virtual void update(sf::Time deltaTime);

private:
    /**
     * @brief
    */
    PlayerScript *player;
    Transform *transform;
    Physics *physic;
    float timer;
};


#endif //RPG_MVC_PLAYEREVENTSHANDLER_HPP
