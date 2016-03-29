//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#include <App/views/IngameView.hpp>
#include <App/models/Map.hpp>
#include "IngameController.hpp"

IngameController::IngameController() {
    view = new IngameView();
    thePlayer = new Player();
    theMap = new Map(thePlayer);
    subController = nullptr;
}

IngameController::~IngameController() {
    delete theMap;
    delete thePlayer;
    delete view;
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

void IngameController::render() {
    if (viewExist()) {
        if (subControllerExist())
            subController->render();
        theMap->render(*view);
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
