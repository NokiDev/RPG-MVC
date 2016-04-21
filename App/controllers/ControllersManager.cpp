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
    nextController = nullptr;
    windowManager = new WindowManager(this);
    windowManager->createWindow(sf::VideoMode(720,480), "MYGAME", sf::Style::Titlebar| sf::Style::Close);
    currentMainController = new MainMenuController();
}

ControllersManager::~ControllersManager() {
    delete currentMainController;
}

IController *ControllersManager::getCurrentMainController() {
    return currentMainController;
}

void ControllersManager::setCurrentMainController(IController *newController) {
    nextController = newController;
}

void ControllersManager::run() {

    if(nextController != nullptr)
    {
        currentMainController->onClose();
        delete currentMainController;
        currentMainController = nextController;
        nextController = nullptr;
    }

    windowManager->clear();
    /*idéalement à lancer dans un thread à part*/
    currentMainController->askForEvents();

    currentMainController->update(app->DeltaTime());
    currentMainController->render();

    windowManager->display();
    //currentMainController->askForRender();
}
