//
// Created by bluedragonfly on 4/18/16.
//

#include "EnemyScript.hpp"
#include "Damageable.hpp"

EnemyScript::EnemyScript(Entity* owner) : ScriptComponent(owner) {

}

EnemyScript::~EnemyScript() {

}



void EnemyScript::update(sf::Time deltaTime) {
    Damageable *damageableScript = owner->getComponent<Damageable>();
    if(damageableScript!= nullptr){
        if(damageableScript->isDead()){
            controller->destroy(owner);
        }
    }
}