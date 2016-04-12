//
// Created by bluedragonfly on 3/29/16.
//

#include "View.hpp"
#include "WindowManager.hpp"
#include <IController.hpp>
#include "IViewComponent.hpp"


View::View(IController *controller) : controller(controller){

}

void View::askForEvent() {
    manager->handleEvent(*this);
}

void View::sendEvent(sf::Event&event) {
    controller->handleEvents(event);
}

void View::addViewComponent(IViewComponent *component) {
        components.push_back(component);
}

sf::Vector2u View::getSize() {
    return manager->getWindowSize();
}
