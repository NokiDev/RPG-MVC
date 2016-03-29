//
// Created by Noki, Timothé Van Deputte on 22/02/2016.
//

#include "ControllersManager.hpp"
#include "MainMenuController.hpp"
#include "IngameController.hpp"
#include <App/App.hpp>
#include "WindowManager.hpp"

ControllersManager::ControllersManager(App* app) {
    this->app = app;
    windowManager = new WindowManager(this);
    windowManager->createWindow(sf::VideoMode(720,480), "MYGAME");
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
    if(currentMainController == nullptr)
        std::cout<<"ERRORNO"<<std::endl;
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
    currentMainController->askForEvents();
    currentMainController->update(app->DeltaTime());
    currentMainController->askForRender();
}
