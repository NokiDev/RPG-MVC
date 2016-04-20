//
// Created by Noki, Timothé Van Deputte on 20/04/2016.
//

#include <App/Components/Transform.hpp>
#include "FactoryScript.hpp"

FactoryScript::FactoryScript(Entity *owner,float delayForFirstLaunch, float spawnTimer) : ScriptComponent(owner){
    this->delayForFirstLaunch = delayForFirstLaunch;
    isFirstLaunch = true;
    this->spawnTimer = spawnTimer;
    timer = 0.f;
}

FactoryScript::~FactoryScript() {

}

void FactoryScript::update(sf::Time deltaTime) {
    Transform * t =  owner->getComponent<Transform>();
    timer += deltaTime.asSeconds();
    if(isFirstLaunch && timer >= delayForFirstLaunch || !isFirstLaunch && timer >= spawnTimer){
        isFirstLaunch = false;
        timer = 0.f;
        controller->instantiate(new Enemy(controller), t->position, t->direction);
    }
}

void FactoryScript::physicsUpdate() {
    ScriptComponent::physicsUpdate();
}
