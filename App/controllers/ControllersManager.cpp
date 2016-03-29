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

IController *ControllersManager::getCurrentMainController() const {
    return currentMainController;
}

void ControllersManager::setCurrentMainController(IController *newMainController) {
    currentMainController = newMainController;
}

void ControllersManager::run() {
    windowManager->clear();
    /*idéalement à lancer dans un thread à part*/
    currentMainController->askForEvents();
    currentMainController->update(app->DeltaTime());
    currentMainController->render();

    windowManager->display();
    //currentMainController->askForRender();
}
