//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#include "IngameView.hpp"

IngameView::IngameView() {
    renderSystem = new RenderSystem();
}

IngameView::~IngameView() {

}



void IngameView::render(sf::RenderWindow &window) const {
    renderSystem->update();
    renderSystem->draw(window);
}

void IngameView::draw(const sf::Drawable &drawable, const sf::RenderStates &states) {

}
