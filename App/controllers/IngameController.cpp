//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#include <App/views/IngameView.hpp>
#include "IngameController.hpp"

IngameController::IngameController() {
    view = new IngameView();
    thePlayer = new Player();
    subController = nullptr;
}

IngameController::~IngameController() {

}

void IngameController::handleEvents(sf::Event &event) {
    if (subControllerExist())
        subController->handleEvents(event);
}

void IngameController::update(sf::Time deltaTime) {
    if (subControllerExist())
        subController->update(deltaTime);
    thePlayer->update(deltaTime);
    thePlayer->physicsUpdate();
}

void IngameController::render(sf::RenderWindow &window) {
    if (viewExist()) {
        if (subControllerExist())
            subController->render(window);
        view->render(window);
    }
}

bool IngameController::viewExist() const { return view != nullptr; }

bool IngameController::subControllerExist() const { return subController != nullptr; }


void IngameController::setSubController(IController *newSubController) {
    if (subController != nullptr) {
        subController->onClose();
        delete subController;
    }
    this->subController = newSubController;
}

void IngameController::onClose() {
    //Save The Game;
}

IController *IngameController::getSubController() {
    return subController;
}
