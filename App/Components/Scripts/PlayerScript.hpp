//
// Created by bluedragonfly on 4/17/16.
//

#ifndef RPG_MVC_PLAYERSCRIPT_HPP
#define RPG_MVC_PLAYERSCRIPT_HPP


#include <App/models/Entity.hpp>
#include <App/Components/ScriptComponent.hpp>
#include <App/Components/Transform.hpp>
#include <App/Components/Physics.hpp>

class Damageable;
class PlayerScript : public ScriptComponent{
public :
    PlayerScript(Entity* owner);
    ~PlayerScript();

    virtual void update(sf::Time deltaTime);

    float getAttackSpeed();
    int getSpeed();

private:

    int speed;
    Damageable* damageableScript;
    float attackSpeed; //Amount attack by seconds
};


#endif //RPG_MVC_PLAYERSCRIPT_HPP
