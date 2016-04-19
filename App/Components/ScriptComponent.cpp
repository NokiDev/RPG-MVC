//
// Created by bluedragonfly on 4/16/16.
//

#include "ScriptComponent.hpp"
#include <App/Systems/ScriptSystem/ScriptSystem.hpp>
#include "Entity.hpp"


ScriptComponent::ScriptComponent(Entity *owner) {
    this->owner = owner;
    controller = owner->getBoss();
    ScriptSystem::scriptSystem->addNewScript(this);
}

ScriptComponent::~ScriptComponent() {
    ScriptSystem::scriptSystem->delBox(this);
}

void ScriptComponent::update(sf::Time deltaTime) {}

void ScriptComponent::physicsUpdate() {}

void ScriptComponent::onCollision(BoxColliderComponent *collider) {}
