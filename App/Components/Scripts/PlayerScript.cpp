//
// Created by bluedragonfly on 4/17/16.
//

#include <App/App.hpp>
#include <App/controllers/MainMenuController.hpp>
#include <App/controllers/GameOverController.hpp>
#include "PlayerScript.hpp"
#include "Damageable.hpp"

PlayerScript::PlayerScript(Entity *owner) : ScriptComponent(owner){
    attackSpeed = 0.1f;
    speed =350;
}

PlayerScript::~PlayerScript() {

}

void PlayerScript::update(sf::Time deltaTime) {
    damageableScript = owner->getScript<Damageable>();
    if(damageableScript!= nullptr){
        if(damageableScript->isDead()){
            //Display GameOver Menu
            IngameController*  c = dynamic_cast<IngameController*>(controller);
            c->setSubController(new GameOverController());
        }
    }
}

float PlayerScript::getAttackSpeed(){
    return attackSpeed;
}


int PlayerScript::getSpeed() {
    return speed;
}
