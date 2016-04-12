//
// Created by Noki, Timothé Van Deputte on 12/02/2016.
//

#include <App/controllers/IngameController.hpp>
#include "App.hpp"

App* App::app;

App::App() {
    if(app == nullptr){
        //Load Settings Preferences
        app = this;
        manager = new ControllersManager(this);
        paused =false;
        time.restart();
    }
    else{
        delete this;
    }
}

App::~App() {
    delete manager;
}

void App::run() {
    running = true;
    while (isRunning()) {
        deltaTime = time.restart();
        manager->run();
    }
}

bool App::isRunning() const {
    return running;
}

bool App::isPaused() const {
    return paused;
}

sf::Time & App::DeltaTime(){
    return deltaTime;
}

void App::close() {
    running = false;
}

App *App::get() {
    return app;
}

ControllersManager *App::getManager() {
    return App::app->manager;
}
