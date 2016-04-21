//
// Created by bluedragonfly on 4/21/16.
//

#include <App/views/GameOverView.hpp>
#include <App/App.hpp>
#include "GameOverController.hpp"
#include "MainMenuController.hpp"

GameOverController::GameOverController() {
    view = new GameOverView(this);
}

GameOverController::~GameOverController() {

}

void GameOverController::handleEvents(sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Return) {
            App::get()->getManager()->setCurrentMainController(new MainMenuController());
        }
    }
}

void GameOverController::update(sf::Time deltaTime) {

}

void GameOverController::render() {
    view->render();
}

void GameOverController::onClose() {

}











