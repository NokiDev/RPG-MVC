//
// Created by Noki, Timothé Van Deputte on 23/02/2016.
//

#include "ViewsManager.hpp"
#include <App/controllers/ControllersManager.hpp>



ViewsManager::ViewsManager(ControllersManager* manager) : manager(manager){
}

ViewsManager::~ViewsManager() {

}

void ViewsManager::createWindow(sf::VideoMode mode, std::string title, sf::Uint32 style, sf::ContextSettings context) {
    window.create(mode, title, style, context);
}

void ViewsManager::run() {
    handleEvent();
    window.clear();
}

void ViewsManager::handleEvent() {
    while(window.pollEvent(event))
    {
        manager->handleEvents(event);
    }
}

void ViewsManager::display() {
    window.display();
}

sf::RenderWindow &ViewsManager::Window() {
    return window;
}


void ViewsManager::clean() {
    window.clear();
}

void ViewsManager::close() {
    window.close();
}
