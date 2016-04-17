//
// Created by bluedragonfly on 4/17/16.
//

#include "PlayerScript.hpp"

PlayerScript::PlayerScript(Entity *owner) : ScriptComponent(owner){
    attackSpeed = 0.2f;
}

PlayerScript::~PlayerScript() {

}

float PlayerScript::getAttackSpeed(){
    return attackSpeed;
}