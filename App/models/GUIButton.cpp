//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#include "GUIButton.hpp"

GUIButton::GUIButton(sf::Vector2f pos, sf::Vector2u size, std::string texture, std::string text, GUIButton::StateButton state) :
        position(pos),
        size(size),
        texture(texture),
        text(text),
        state(state){

}

GUIButton::~GUIButton() {

}

void GUIButton::setPosition(sf::Vector2f pos) {
    position = pos;
}

void GUIButton::setSize(sf::Vector2u size) {
    this->size = size;
}

void GUIButton::setText(std::string text) {
    this->text = text;
}

void GUIButton::setState(GUIButton::StateButton state) {
    this->state = state;
}

std::string GUIButton::getTexture() {
    return texture;
}

sf::Vector2f GUIButton::getPosition() {
    return position;
}

sf::Vector2u GUIButton::getSize() {
    return size;
}

std::string GUIButton::getText() {
    return text;
}

GUIButton::StateButton GUIButton::getState() {
    return state;
}
