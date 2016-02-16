//
// Created by Noki, Timothé Van Deputte on 12/02/2016.
//

#include <App/controllers/IngameController.hpp>
#include "App.hpp"

App::App() {

    ///Load Settings Preferences
    window.create(sf::VideoMode(720, 480), "title");
    time.restart();
}

App::~App() {

}

void App::handleEvents() {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            running = false;
        }
        else if (event.type == sf::Event::Resized) {

        }
        else if (event.type == sf::Event::LostFocus) {

        }
        else if (event.type == sf::Event::GainedFocus) {

        }
        else {
            currentMainController->handleInputs(event);
        }
    }
}

void App::run() {
    running = true;
    currentMainController = new IngameController();
    while (running) {
        handleEvents();
        deltaTime = time.restart();
        window.clear();
        currentMainController->update(deltaTime);
        currentMainController->render(window);
        window.display();
    }
}

void App::setMainController(IController *newMainController) {
    if (mainControllerExist()) {
        currentMainController->onClose();
        delete currentMainController;
    }
    currentMainController = newMainController;
}

bool App::mainControllerExist() const {
    return currentMainController != nullptr;
}

IController *App::getCurrentMainController() const {
    return currentMainController;
}


bool App::isRunning() const {
    return running;
}

bool App::isPaused() const {
    return paused;
}
