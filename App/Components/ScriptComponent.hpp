//
// Created by bluedragonfly on 4/16/16.
//

#ifndef RPG_MVC_SCRIPTCOMPONENT_HPP
#define RPG_MVC_SCRIPTCOMPONENT_HPP


#include <App/controllers/IngameController.hpp>
#include "Component.hpp"

class ScriptComponent{
public :
    ScriptComponent(Entity* owner);

    virtual ~ScriptComponent();

    virtual void update(sf::Time deltaTime);

    virtual void physicsUpdate();

    virtual void onCollision(BoxColliderComponent* collider);
    virtual void onTriggerEnter(TriggerCollision* collider);
    virtual void onTriggerStay(TriggerCollision* collider);
    virtual void onTriggerExit(TriggerCollision* collider);

    Entity& getOwner() const {
        return *owner;
    }


protected:
    IController * controller;
    Entity* owner;
};


#endif //RPG_MVC_SCRIPTCOMPONENT_HPP
