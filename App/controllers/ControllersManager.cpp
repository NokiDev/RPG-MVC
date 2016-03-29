//
// Created by Noki, Timothé Van Deputte on 22/02/2016.
//

#include "ControllersManager.hpp"
#include "MainMenuController.hpp"
#include "IngameController.hpp"
#include <App/App.hpp>
#include <App/views/ViewsManager.hpp>

ControllersManager::ControllersManager(App* app) {
    this->app = app;
    viewsManager = new ViewsManager(this);
    viewsManager->createWindow(sf::VideoMode(720,480), "MYGAME");
    currentMainController = new IngameController();
}

ControllersManager::~ControllersManager() {
    delete currentMainController;
}

void ControllersManager::handleEvents(sf::Event &event) {
    ///Events de base
    if(event.type == sf::Event::Closed)
    {
        app->close();
    }
    currentMainController->handleEvents(event);
}

IController *ControllersManager::getCurrentMainController() const {
    return currentMainController;
}

void ControllersManager::setCurrentMainController(IController *newMainController) {
    currentMainController = newMainController;
}

void ControllersManager::run() {
    /*idéalement à lancer dans un thread à part*/
    viewsManager->run();
    currentMainController->update(app->DeltaTime());
    viewsManager->clean();
    currentMainController->render();
    viewsManager->display();
}
