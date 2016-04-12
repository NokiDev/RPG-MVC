//
// Created by bluedragonfly on 3/29/16.
//

#include <App/models/Ressources.hpp>
#include <App/App.hpp>
#include "ViewComponent.hpp"
#include "WindowManager.hpp"

ViewComponent::ViewComponent(std::string textureName) {
    texture = Ressources::Load(textureName);
    sprite.setTexture(texture);
}

void ViewComponent::draw(View& view) {
    view.draw(sprite);
}

void ViewComponent::updatePosition(sf::Vector2f position) {
    sprite.setPosition(position);
}

void ViewComponent::updateRect(sf::IntRect textRect) {
    sprite.setTextureRect(textRect);
}

ViewComponent::ViewComponent() {

}
