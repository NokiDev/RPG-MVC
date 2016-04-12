//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#include <App/models/Ressources.hpp>
#include <App/Systems/RenderSystem/RenderSystem.hpp>
#include "IViewComponent.hpp"
#include "RenderComponent.hpp"

RenderComponent::RenderComponent(Entity *owner, std::string textureName) {
    this->owner = owner;
    RenderSystem::renderSystem->addSprite(this);
}

RenderComponent::~RenderComponent() {
    RenderSystem::renderSystem->delSprite(this);
}

void RenderComponent::update(sf::Time deltaTime) {
    sprite.setPosition(owner->getPosition());
}

void RenderComponent::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

/*void RenderComponent::setFragmentShader(std::string fileName) {

}

void RenderComponent::setVertexShader(std::string fileName) {

}

void RenderComponent::setShader(sf::Shader *shader) {

}*/void RenderComponent::rotate(int scaley , int scalex) {
    sprite.setScale(scalex, scaley);
}
