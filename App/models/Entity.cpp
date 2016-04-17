//
// Created by Noki, Timothé Van Deputte on 16/02/2016.
//

#include "Entity.hpp"
#include "Component.hpp"

int Entity::nextId = 0;

Entity::Entity(IController* boss) : id(nextId++), boss(boss){
    if(boss == nullptr)
        std::cout<<"LOL ERROR"<<std::endl;
};


sf::Vector2f Entity::getDirection() {
    return direction;
}

sf::Vector2u Entity::getSize() {
    return size;
}

std::string Entity::getComponentName(Component* component) {
    return typeid(*component).name();
}
