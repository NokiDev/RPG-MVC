//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#include "GUIButton.hpp"
#include <iostream>
#include "Ressources.hpp"


GUIButton::GUIButton(IController* boss, sf::Vector2f pos, std::string text, GUIButton::StateButton state) {
    GUIButton(boss, pos, sf::Vector2u(100, 50), "GuiMenu.png", text, state);
}

GUIButton::GUIButton(IController* boss, sf::Vector2f pos, sf::Vector2u size, std::string texture, std::string text, GUIButton::StateButton state) :
        boss(boss),
        position(pos),
        size(size),
        texture(texture),
        textStr(text),
        state(state){

    viewRenderer = new ViewComponent(texture);
    viewRenderer->updateRect(sf::IntRect(0,0, size.x, size.y));
    viewRenderer->updatePosition(pos);

    boss->getView()->addViewComponent(viewRenderer);

    font.loadFromFile("Ressources/fonts/blake2.ttf");

    this->text = sf::Text(text,font);

    this->text.setPosition(pos.x+ size.x/2, pos.y);

}

GUIButton::~GUIButton() {

}

void GUIButton::update() {

}

void GUIButton::render(View &view) {
    view.draw(text);
}

void GUIButton::setPosition(sf::Vector2f pos) {
    position = pos;
}

void GUIButton::setSize(sf::Vector2u size) {
    this->size = size;
}

void GUIButton::setText(std::string text) {
    this->textStr = text;
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
    return textStr;
}

GUIButton::StateButton GUIButton::getState() {
    return state;
}


