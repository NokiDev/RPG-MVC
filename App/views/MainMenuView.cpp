//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#include "MainMenuView.hpp"

MainMenuView::MainMenuView() {


}

MainMenuView::~MainMenuView() {

}

void MainMenuView::render(sf::RenderWindow &window) const{
    for(GuiButtonView * button : buttons)
    {
        button->render(window);
    }
}

void MainMenuView::draw(const sf::Drawable &drawable, const sf::RenderStates &states) {

}