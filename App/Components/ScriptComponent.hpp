//
// Created by bluedragonfly on 4/16/16.
//

#ifndef RPG_MVC_SCRIPTCOMPONENT_HPP
#define RPG_MVC_SCRIPTCOMPONENT_HPP


#include <App/controllers/IngameController.hpp>
#include "Component.hpp"

class ScriptComponent : public Component{
public :
    ScriptComponent(Entity* owner);

    virtual ~ScriptComponent();

    virtual void update(sf::Time deltaTime);

    virtual void physicsUpdate();

    virtual void onCollision(BoxColliderComponent* collider);


protected:
    IController * controller;
};


#endif //RPG_MVC_SCRIPTCOMPONENT_HPP
