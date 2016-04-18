//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#include <App/views/IngameView.hpp>
#include <App/models/Map.hpp>
#include <App/Systems/CollisionSystem/CollisionSystem.hpp>
#include <App/Systems/EventSystem/EventsSystem.hpp>
#include <App/Systems/ScriptSystem/ScriptSystem.hpp>

#include "IngameController.hpp"

IngameController::IngameController() {
    view = new IngameView(this);
    collSys = new CollisionSystem();
    scriptSys = new ScriptSystem();
    eventSys = new EventsSystem();
    thePlayer = new Player(this);
    entities.insert(new Enemy(this));
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
    eventSys->handleEvents(event);
}

void IngameController::update(sf::Time deltaTime) {

    for(auto entity : entitiesToDestroy){
        entities.erase(entity);
        delete entity;
    }
    entitiesToDestroy.clear();
    thePlayer->physicsUpdate();
    for(auto entity : entities){
        entity->physicsUpdate();
    }
    scriptSys->physicsUpdate();

    collSys->checkCollisions();
    collSys->update(deltaTime);

    eventSys->update(deltaTime);
    thePlayer->update(deltaTime);

    for(auto entity : entities) {
        entity->update(deltaTime);
    }

    scriptSys->update(deltaTime);
}

void IngameController::render() {
    if (viewExist()) {
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
    entities.insert(entity);
    entity->setPosition(position);
    entity->setDirection(direction);
    entity->physicsUpdate();

    return entity;
}

void IngameController::destroy(Entity *entity) {
    entitiesToDestroy.push_back(entity);
}
