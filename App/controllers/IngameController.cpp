//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#include <App/views/IngameView.hpp>
#include <App/models/Map.hpp>
#include <App/Systems/CollisionSystem/CollisionSystem.hpp>
#include <App/Systems/EventSystem/EventsSystem.hpp>
#include "IngameController.hpp"

IngameController::IngameController() {
    view = new IngameView(this);
    collSys = new CollisionSystem();
    eventSys = new EventsSystem();
    thePlayer = new Player(this);
    theMap = new Map(thePlayer);
    subController = nullptr;
}

IngameController::~IngameController() {
    delete theMap;
    delete thePlayer;
    delete view;
}

void IngameController::handleEvents(sf::Event &event) {
    IController::handleEvents(event);
    if (subControllerExist())
        subController->handleEvents(event);
    eventSys->handleEvents(event);
}

void IngameController::update(sf::Time deltaTime) {
    if (subControllerExist())
        subController->update(deltaTime);
    thePlayer->update(deltaTime);
    thePlayer->physicsUpdate();
    for(auto entity : entities){
        entity->update();
        entity->physicsUpdate();
    }
    collSys->checkCollisions();
}

void IngameController::render() {
    if (viewExist()) {
        if (subControllerExist())
            subController->render();
        view->render();
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

Entity* IngameController::instantiate(Entity *entity, sf::Vector2f position, sf::Vector2f direction) {

    entities.push_back(entity);
    entity->setPosition(position);
    entity->setDirection(direction);

    return entity;
}
