//
// Created by bluedragonfly on 4/16/16.
//

#ifndef RPG_MVC_LIVETIMERSCRIPT_HPP
#define RPG_MVC_LIVETIMERSCRIPT_HPP


#include <App/Components/ScriptComponent.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>

class Entity;

class BoxColliderComponent;

class LiveTimerScript : public ScriptComponent {
public :
    LiveTimerScript(Entity *owner, float timeToLive);

    ~LiveTimerScript();

    virtual void update(sf::Time deltaTime);

private :

    float timer;
    float timeToLive;
};


#endif //RPG_MVC_LIVETIMERSCRIPT_HPP
