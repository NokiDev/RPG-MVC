//
// Created by bluedragonfly on 4/18/16.
//

#ifndef RPG_MVC_LASERSCRIPT_HPP
#define RPG_MVC_LASERSCRIPT_HPP

#include <App/Systems/CollisionSystem/CollisionSystem.hpp>
#include "ScriptComponent.hpp"

class Entity;

class LaserScript : public ScriptComponent {
public :
    LaserScript(Entity *owner, std::string attackLayer);

    ~LaserScript();

    virtual void update(sf::Time deltaTime);

    virtual void physicsUpdate();

    virtual void onTriggerEnter(TriggerCollision *collision);

private:

    Physics *physics;
    std::string attackLayer;
    int speed;

};


#endif //RPG_MVC_LASERSCRIPT_HPP
