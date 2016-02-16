//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#include "RenderSystem.hpp"

RenderSystem *RenderSystem::renderSystem;

RenderSystem::RenderSystem() {
    if (renderSystem != nullptr)
        delete this;
    else
        renderSystem = this;
}

RenderSystem::~RenderSystem() {

}

void RenderSystem::addSprite(RenderComponent *sprite) {
    renderComponents.insert(sprite);
}

void RenderSystem::delSprite(RenderComponent *sprite) {
    renderComponents.erase(sprite);
}

void RenderSystem::update() {
    for (RenderComponent *renderComponent : renderComponents) {
        renderComponent->update();
    }
}

void RenderSystem::draw(sf::RenderWindow &window) {
    for (RenderComponent *renderComponent : renderComponents) {
        renderComponent->draw(window);
    }
}
