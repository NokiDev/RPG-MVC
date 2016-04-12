//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#include <App/views/MainMenuView.hpp>
#include <App/models/GUIButton.hpp>
#include "MainMenuController.hpp"

MainMenuController::MainMenuController() {
    view = new MainMenuView(this);
    buttons.push_back(new GUIButton(this, sf::Vector2f(50,50), sf::Vector2u(200, 40), "GuiMenu.png","Play"));
}


MainMenuController::~MainMenuController() {

}


void MainMenuController::handleEvents(sf::Event &event) {
    IController::handleEvents(event);
}

void MainMenuController::update(sf::Time deltaTime) {
    for(GUIButton* button : buttons){
        button->update();
    }
}

void MainMenuController::render() {
    view->render();
}

void MainMenuController::setSubController(IController *newSubController) {

}

void MainMenuController::onClose() {

}
