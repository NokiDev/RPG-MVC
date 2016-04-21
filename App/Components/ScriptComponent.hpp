//
// Created by bluedragonfly on 4/16/16.
//

#ifndef RPG_MVC_SCRIPTCOMPONENT_HPP
#define RPG_MVC_SCRIPTCOMPONENT_HPP


#include <App/controllers/IngameController.hpp>
#include "Component.hpp"

/**
 * @brief basic class for Scripts, allow an entity to have different behaviours
 **/
class ScriptComponent {
public :
    /**
     * @brief default ctor
     * @param Entity * owner of the component
     **/
    ScriptComponent(Entity *owner);

    /**
     * @brief dtor
     **/
    virtual ~ScriptComponent();

    /**
     * @brief update each frames the component (scripts)
     * @param sf::Time time between two frames
     **/
    virtual void update(sf::Time deltaTime);

    virtual void physicsUpdate();

    virtual void onCollision(BoxColliderComponent *collider);

    virtual void onTriggerEnter(TriggerCollision *collider);

    virtual void onTriggerStay(TriggerCollision *collider);

    virtual void onTriggerExit(TriggerCollision *collider);

    Entity &getOwner() const {
        return *owner;
    }


protected:
    IController *controller;
    Entity *owner;
};


#endif //RPG_MVC_SCRIPTCOMPONENT_HPP
