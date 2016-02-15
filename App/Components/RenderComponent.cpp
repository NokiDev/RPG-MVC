//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#include <App/models/Ressources.hpp>
#include "RenderComponent.hpp"

RenderComponent::RenderComponent(Entity *owner, std::string textureName) {
    this->owner = owner;
    sprite.setTexture(Ressources::Load(textureName));
    sprite.setPosition(owner->position);
   // sprite.setColor()
    //RenderSystem::addSprite(this);

}

RenderComponent::~RenderComponent() {
    //RenderSystem::delSprite(this);
}

void RenderComponent::update(sf::Time deltaTime) {
    sprite.setPosition(owner->position);
}

void RenderComponent::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

/*void RenderComponent::setFragmentShader(std::string fileName) {

}

void RenderComponent::setVertexShader(std::string fileName) {

}

void RenderComponent::setShader(sf::Shader *shader) {

}*/
