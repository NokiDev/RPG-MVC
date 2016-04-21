//
// Created by Noki, Timothé Van Deputte on 23/02/2016.
//

#include "WindowManager.hpp"
#include <App/controllers/ControllersManager.hpp>
#include <iostream>
#include "View.hpp"


WindowManager *WindowManager::windowManager;

WindowManager::WindowManager(ControllersManager *manager) : manager(manager) {
    if (windowManager == nullptr) {
        windowManager = this;
    }
    else {
        std::cerr << "Warning : Instantiate viewsManager for the 2nd Time, but it's singleton, Fix This !" << std::endl;
        delete this;
    }
}

WindowManager::~WindowManager() {

}

void WindowManager::createWindow(sf::VideoMode mode, std::string title, sf::Uint32 style, sf::ContextSettings context) {
    window.create(mode, title, style, context);
    window.setVerticalSyncEnabled(true);
}

void WindowManager::handleEvent(View &view) {
    while (window.pollEvent(event)) {
        view.sendEvent(event);
    }
}

bool WindowManager::isKeyPressed(sf::Keyboard::Key key) {
    return sf::Keyboard::isKeyPressed(key);
}

void WindowManager::display() {
    window.display();
}

sf::RenderWindow &WindowManager::Window() {
    return window;
}


void WindowManager::clear() {
    window.clear();
}

void WindowManager::close() {
    window.close();
}

WindowManager *WindowManager::get() {
    return windowManager;
}

sf::Vector2u WindowManager::getWindowSize() {
    return window.getSize();
}
