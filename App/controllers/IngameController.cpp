//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#include <App/views/IngameView.hpp>
#include <App/models/Map.hpp>
#include <App/Systems/CollisionSystem/CollisionSystem.hpp>
#include <App/Systems/EventSystem/EventsSystem.hpp>
#include <App/Systems/ScriptSystem/ScriptSystem.hpp>
#include <App/Components/Transform.hpp>

#include "IngameController.hpp"

IngameController::IngameController() {
    view = new IngameView(this);
    //Init Systems
    eventSys = new EventsSystem();
    collSys = new CollisionSystem();
    physicsSys = new PhysicsSystem();
    scriptSys = new ScriptSystem();
    //Init Entities
    thePlayer = new Player(this);
    entities.insert(new Enemy(this));
    //Init Map
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
    eventSys->update(deltaTime);
    //physicsSys->updatePhysicsScripts(); /// Update Physics Stuff like movement rotation, collision test etc.. .....
    scriptSys->physicsUpdate();

    collSys->checkCollisions();///Verify the movement is safe, not colliding else it will determine the final movement
    collSys->updateComponents(deltaTime);///Update the coliders components (update position)
    physicsSys->updateComponents(deltaTime);//Finalize the movement by adding position and reset velocity to zero
    scriptSys->update(deltaTime);//

    thePlayer->update(deltaTime);
    for(auto entity : entities){
        entity->update(deltaTime);
    }
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

Entity* IngameController::instantiate(Entity *entity, sf::Vector2f position, sf::Vector2i direction) {
    entities.insert(entity);
    Transform * t = entity->getComponent<Transform>();
    t->position = position;
    t->direction = direction;

    return entity;
}

void IngameController::destroy(Entity *entity) {
    entitiesToDestroy.push_back(entity);
}
