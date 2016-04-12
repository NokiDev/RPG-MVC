//
// Created by bluedragonfly on 4/12/16.
//

#include "ViewTextComponent.hpp"

ViewTextComponent::ViewTextComponent(std::string text) {
    font.loadFromFile("Ressources/fonts/space age.ttf");
    this->text = sf::Text(text,font);
}

void ViewTextComponent::updatePosition(sf::Vector2f position) {
    text.setPosition(position);
}

void ViewTextComponent::draw(View &view) {
    view.draw(text);
}
