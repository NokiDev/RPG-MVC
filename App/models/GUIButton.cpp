//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#include "GUIButton.hpp"
#include <iostream>
#include "Ressources.hpp"
#include <App/views/ViewTextComponent.hpp>
#include <App/views/ViewSpriteComponent.hpp>
#include "IController.hpp"


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

    //SpriteRenderer reference, allow us to keep dependency
    viewRenderer = boss->newSpriteRenderer(texture);
    viewRenderer->updateRect(sf::IntRect(0,0, size.x, size.y));
    viewRenderer->updatePosition(pos);

    //TextRenderer reference, allow us to keep dependency
    textRenderer = boss->newTextRenderer(text);
    textRenderer->updatePosition(sf::Vector2f(pos.x + size.x/2 - 50, pos.y));
}

GUIButton::~GUIButton() {
    delete textRenderer;
    delete viewRenderer;
}

void GUIButton::update() {

}

void GUIButton::setPosition(sf::Vector2f pos) {
    position = pos;
    viewRenderer->updatePosition(pos);
    textRenderer->updatePosition(pos);
}

void GUIButton::setSize(sf::Vector2u size) {
    this->size = size;
}

void GUIButton::setText(std::string text) {
    this->textStr = text;
}

void GUIButton::setState(GUIButton::StateButton state) {
    switch(state){
        case SELECTED:
            viewRenderer->updateRect(sf::IntRect(0, 40, size.x, size.y));
            break;
        case NORMAL :
            viewRenderer->updateRect(sf::IntRect(0, 0, size.x, size.y));
            break;
        case DISABLED:
            viewRenderer->updateRect(sf::IntRect(0, 80, size.x, size.y));
            break;
        default:
            break;
    }
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
