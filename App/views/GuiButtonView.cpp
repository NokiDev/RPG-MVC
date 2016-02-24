//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#include <App/models/Ressources.hpp>
#include "GuiButtonView.hpp"

GuiButtonView::GuiButtonView(GUIButton *button) {
    this->button = button;
    sf::Texture & texture = Ressources::Load(button->getTexture());
    sprite.setTexture(texture);
}

GuiButtonView::~GuiButtonView() {

}

void GuiButtonView::render(sf::RenderWindow &window) {
    sprite.setPosition(button->getPosition());

}
