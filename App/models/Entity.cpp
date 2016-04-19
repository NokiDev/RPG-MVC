//
// Created by Noki, Timothé Van Deputte on 16/02/2016.
//

#include <App/Components/Transform.hpp>
#include <App/Components/ScriptComponent.hpp>
#include "Entity.hpp"
#include "Component.hpp"
#include "Transform.hpp"

int Entity::nextId = 0;

Entity::Entity(IController* boss) : id(nextId++){
    if(boss == nullptr)
        std::cout<<"LOL ERROR"<<std::endl;
    else{
        this->boss = boss;
        addComponent(new Transform(this));
    }
};

Entity::~Entity() {
    removeComponent<Transform>();
}

std::string Entity::getComponentName(Component* component) {
    return typeid(*component).name();
}


std::string Entity::getComponentName(ScriptComponent* component) {
    return typeid(*component).name();
}

void Entity::OnCollision(Entity *entity, BoxColliderComponent *collider) {
    for(auto script : entity->scripts){
        ScriptComponent * scriptComponent = script.second;
        scriptComponent->onCollision(collider);
    }
}
