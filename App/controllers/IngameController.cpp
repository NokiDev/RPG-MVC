//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#include <App/views/IngameView.hpp>
#include <App/Systems/CollisionSystem/CollisionSystem.hpp>
#include <App/Systems/EventSystem/EventsSystem.hpp>
#include <App/Systems/ScriptSystem/ScriptSystem.hpp>
#include <App/Components/Transform.hpp>
#include <App/models/EnemyFactory.hpp>

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
    time.Zero;

    //La manière la plus dégeulasse de faire un spawner, mais pas le time !
    instantiate(new EnemyFactory(this, 1.f, 2.f), sf::Vector2f(660.f, 70.f), sf::Vector2i(-1, 0));


    //entities.insert(new Enemy(this));

    subController = nullptr;
}

IngameController::~IngameController() {
    for (auto entity : entities) {
        delete entity;
    }
    entities.clear();
    delete thePlayer;
    delete eventSys;
    delete collSys;
    delete physicsSys;
    delete scriptSys;
    delete view;
}

void IngameController::handleEvents(sf::Event &event) {
    IController::handleEvents(event);
    if (subControllerExist())
        subController->handleEvents(event);
    else {
        if (event.type == sf::Event::KeyPressed) {
            ///EVENT FOR BUTTONS :
            if (event.key.code == sf::Keyboard::Escape) {
                std::cout << "PAUSE" << std::endl;
            }
        }
        eventSys->handleEvents(event);
    }
}

void IngameController::update(sf::Time deltaTime) {
    if (subControllerExist()) {
        subController->update(deltaTime);
    }
    else { //Paused
        for (auto entity : entitiesToDestroy) {
            entities.erase(entity);
            delete entity;
        }

        collSys->updateComponents(deltaTime);///Update the coliders components (update position)

        entitiesToDestroy.clear();
        eventSys->update(deltaTime);
        scriptSys->physicsUpdate();

        collSys->checkCollisions();///Verify the movement is safe, not colliding else it will determine the final movement
        physicsSys->updateComponents(deltaTime);//Finalize the movement by adding position and reset velocity to zero
        scriptSys->update(deltaTime);//

        thePlayer->update(deltaTime);
        for (auto entity : entities) {
            entity->update(deltaTime);
        }
    }

    time += deltaTime;
}

void IngameController::render() {
    if (viewExist()) {
        view->render();
        if (subControllerExist()) {
            subController->render();
        }
    }
}

bool IngameController::viewExist() const { return view != nullptr; }

bool IngameController::subControllerExist() const { return subController != nullptr; }


void IngameController::setSubController(IController *newSubController) {
    if (subController != nullptr) {
        subController->onClose();
        delete subController;
    }
    subController = newSubController;
}

IController *IngameController::getSubController() {
    return subController;
}

Entity *IngameController::instantiate(Entity *entity, sf::Vector2f position, sf::Vector2i direction) {
    entities.insert(entity);
    Transform *t = entity->getComponent<Transform>();
    t->position = position;
    t->direction = direction;

    return entity;
}

void IngameController::destroy(Entity *entity) {
    if (entitiesToDestroy.find(entity) == entitiesToDestroy.end())///Test if the Entity is deleted Twice
        entitiesToDestroy.insert(entity);
}

void IngameController::onClose() {
    //Save The Game;
}

Player *IngameController::getPlayer() {
    return thePlayer;
}

float IngameController::getTime() {
    return time.asSeconds();
}
