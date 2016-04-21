//
// Created by Noki, Timothé Van Deputte on 20/04/2016.
//

#include <App/Components/Transform.hpp>
#include <time.h>

#include "FactoryScript.hpp"

FactoryScript::FactoryScript(Entity *owner, float delayForFirstLaunch, float spawnTimer) : ScriptComponent(owner) {
    this->delayForFirstLaunch = delayForFirstLaunch;
    isFirstLaunch = true;
    this->spawnTimer = spawnTimer;
    timer = 0.f;
    srand(time(NULL));
}

FactoryScript::~FactoryScript() {

}

void FactoryScript::update(sf::Time deltaTime) {
    Transform *t = owner->getComponent<Transform>();
    timer += deltaTime.asSeconds();
    if (isFirstLaunch && timer >= delayForFirstLaunch || !isFirstLaunch && timer >= spawnTimer) {
        isFirstLaunch = false;
        timer = 0.f;
        float posY = (float) (rand() % 460 + 10);
        controller->instantiate(new Enemy(controller), sf::Vector2f(650.f, posY), t->direction);
    }
}

void FactoryScript::physicsUpdate() {
    ScriptComponent::physicsUpdate();
}
