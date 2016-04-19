//
// Created by bluedragonfly on 4/17/16.
//

#include "PlayerScript.hpp"

PlayerScript::PlayerScript(Entity *owner) : ScriptComponent(owner){
    attackSpeed = 0.2f;
    speed =350;
}

PlayerScript::~PlayerScript() {

}

float PlayerScript::getAttackSpeed(){
    return attackSpeed;
}


int PlayerScript::getSpeed() {
    return speed;
}
