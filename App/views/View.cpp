//
// Created by bluedragonfly on 3/29/16.
//

#include "View.hpp"
#include "WindowManager.hpp"
#include <IController.hpp>
#include "IViewComponent.hpp"


View* View::currentView;

View::View(IController *controller) : controller(controller){
    currentView = this;
}

void View::askForEvent() {
    manager->handleEvent(*this);
}

void View::sendEvent(sf::Event&event) {
    controller->handleEvents(event);
}

void View::addViewComponent(IViewComponent *component) {
    components.insert(component);
}

void View::delViewComponent(IViewComponent* component){
    components.erase(component);
}

sf::Vector2u View::getSize() {
    return manager->getWindowSize();
}

bool View::isKeyPressed(sf::Keyboard::Key key) {
    return sf::Keyboard::isKeyPressed(key);
}
