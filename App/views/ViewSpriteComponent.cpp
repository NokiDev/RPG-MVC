//
// Created by bluedragonfly on 4/12/16.
//

#include <App/Helpers/Ressources.hpp>
#include "ViewSpriteComponent.hpp"

ViewSpriteComponent::ViewSpriteComponent(std::string textureName) {
    texture = Ressources::Load(textureName);
    sprite.setTexture(texture);
}

void ViewSpriteComponent::draw(View& view) {
    view.draw(sprite);
}

void ViewSpriteComponent::updatePosition(sf::Vector2f position) {
    sprite.setPosition(position);
}

void ViewSpriteComponent::updateRect(sf::IntRect textRect) {
    sprite.setTextureRect(textRect);
}