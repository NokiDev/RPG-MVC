//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#include <App/views/MainMenuView.hpp>
#include <App/models/GUIButton.hpp>
#include <App/App.hpp>
#include "MainMenuController.hpp"
#include "IngameController.hpp"

MainMenuController::MainMenuController() {
    view = new MainMenuView(this);
    buttons.push_back(new GUIButton(this, sf::Vector2f(view->getSize().x/2 - 100, view->getSize().y/2 - 50), sf::Vector2u(200, 40), "GuiMenu.png", "Play"));
    buttons.push_back(new GUIButton(this, sf::Vector2f(view->getSize().x/2 - 100, view->getSize().y/2), sf::Vector2u(200, 40), "GuiMenu.png", "Options"));
    buttons.push_back(new GUIButton(this, sf::Vector2f(view->getSize().x/2 - 100, view->getSize().y/2 + 50), sf::Vector2u(200, 40), "GuiMenu.png", "Quit"));
    selectedButton = buttons.begin();
    GUIButton* button = *selectedButton;
    button->setState(GUIButton::StateButton::SELECTED);
}


MainMenuController::~MainMenuController() {

}


void MainMenuController::handleEvents(sf::Event &event) {
    IController::handleEvents(event);
    if (event.type == sf::Event::KeyPressed) {
        ///EVENT FOR BUTTONS :
        if (event.key.code == sf::Keyboard::Return) {
            fireButton();
        }
        else if (event.key.code == sf::Keyboard::Up) {
            goUp();
        }
        else if (event.key.code == sf::Keyboard::Down) {
            goDown();
        }
    }
}

void MainMenuController::update(sf::Time deltaTime) {
    for (GUIButton *button : buttons) {
        button->update();
    }
}

void MainMenuController::render() {
    view->render();
}

void MainMenuController::goDown() {
    GUIButton *button = *selectedButton;
    button->setState(GUIButton::StateButton::NORMAL);
    if (selectedButton == buttons.end()-1) {
        selectedButton = buttons.begin();
    }
    else {
        selectedButton++;
    }
    button = *selectedButton;
    button->setState(GUIButton::StateButton::SELECTED);
}

void MainMenuController::goUp() {
    GUIButton *button = *selectedButton;
    button->setState(GUIButton::StateButton::NORMAL);
    if (selectedButton == buttons.begin()) {
        selectedButton = buttons.end()-1; // Last value of a vector is the end of the array not a value
    }
    else {
        selectedButton--;
    }
    button = *selectedButton;
    button->setState(GUIButton::StateButton::SELECTED);
}

void MainMenuController::fireButton() {
    GUIButton * button = *selectedButton;
    std::string text = button->getText();
    if (text == "Play") {
        ///Launch Game;
        App::getManager()->setCurrentMainController(new IngameController());
    }
    else if(text == "Quit"){
        App::get()->close();
    }
}

void MainMenuController::setSubController(IController *newSubController) {

}

void MainMenuController::onClose() {

}
