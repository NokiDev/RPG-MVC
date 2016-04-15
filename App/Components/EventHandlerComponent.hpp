//
// Created by bluedragonfly on 4/14/16.
//

#ifndef RPG_MVC_EVENTHANDLERCOMPONENT_HPP
#define RPG_MVC_EVENTHANDLERCOMPONENT_HPP


#include <SFML/Window/Event.hpp>
#include "Component.hpp"

class EventHandlerComponent : public Component {

public :
    EventHandlerComponent(Entity* owner);
    ~EventHandlerComponent();

    virtual void handleEvents(sf::Event)=0;
    virtual void update(sf::Time deltaTime)=0;

protected:
};


#endif //RPG_MVC_EVENTHANDLERCOMPONENT_HPP
