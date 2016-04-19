//
// Created by bluedragonfly on 4/15/16.
//

#ifndef RPG_MVC_PLAYEREVENTSHANDLER_HPP
#define RPG_MVC_PLAYEREVENTSHANDLER_HPP


#include <App/models/Entity.hpp>
#include <App/Components/EventHandlerComponent.hpp>
#include <App/Components/Scripts/PlayerScript.hpp>

class PlayerEventsHandler : public EventHandlerComponent {
    public :
        PlayerEventsHandler(Entity* owner);
        ~PlayerEventsHandler();

        virtual void handleEvents(sf::Event event);
        virtual void update(sf::Time time);

private:
        PlayerScript * player;
        Transform* transform;
        Physics* physic;
        float timer;
};


#endif //RPG_MVC_PLAYEREVENTSHANDLER_HPP
