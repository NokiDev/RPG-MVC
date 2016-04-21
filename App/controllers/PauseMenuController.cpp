//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#include <App/views/PauseMenuView.hpp>
#include <App/models/GUIButton.hpp>
#include <App/App.hpp>
#include "PauseMenuController.hpp"
#include "IngameController.hpp"

PauseMenuController::PauseMenuController(IngameController* ingameC) : ingameController(ingameC) {
    view = new PauseMenuView(this);

    buttons.push_back(new GUIButton(this, sf::Vector2f(view->getSize().x/2 - 100, view->getSize().y/2 - 50), sf::Vector2u(200, 40), "GuiMenu.png", "Continue"));
    buttons.push_back(new GUIButton(this, sf::Vector2f(view->getSize().x/2 - 100, view->getSize().y/2), sf::Vector2u(200, 40), "GuiMenu.png", "Quit"));
    selectedButton = buttons.begin();
    GUIButton* button = *selectedButton;
    button->setState(GUIButton::StateButton::SELECTED);
}


PauseMenuController::~PauseMenuController() {

}


void PauseMenuController::handleEvents(sf::Event &event) {
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

void PauseMenuController::update(sf::Time deltaTime) {
    for (GUIButton *button : buttons) {
        button->update();
    }
}

void PauseMenuController::render() {
    view->render();
}

void PauseMenuController::goDown() {
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

void PauseMenuController::goUp() {
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

void PauseMenuController::fireButton() {
    GUIButton * button = *selectedButton;
    std::string text = button->getText();
    if (text == "Continue") {
        ///Continue Game;
        App::getManager()->setCurrentMainController(ingameController);
    }
    else if(text == "Quit"){
        App::get()->close();
    }
}

void PauseMenuController::setSubController(IController *newSubController) {

}

void PauseMenuController::onClose() {

}
