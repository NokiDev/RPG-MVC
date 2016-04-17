//
// Created by bluedragonfly on 4/17/16.
//

#ifndef RPG_MVC_PLAYERSCRIPT_HPP
#define RPG_MVC_PLAYERSCRIPT_HPP


#include <App/models/Entity.hpp>
#include <App/Components/ScriptComponent.hpp>

class PlayerScript : public ScriptComponent{
public :
    PlayerScript(Entity* owner);
    ~PlayerScript();

    float getAttackSpeed(){
        return attackSpeed;
    }

private:
    float attackSpeed; //Amount attack by seconds
};


#endif //RPG_MVC_PLAYERSCRIPT_HPP
