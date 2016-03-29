//
// Created by bluedragonfly on 3/29/16.
//

#include "View.hpp"
#include "WindowManager.hpp"
#include <IController.hpp>
#include <SFML/Window/Event.hpp>


View::View(IController *controller) : controller(controller){

}

void View::askForEvent() {
    manager->handleEvent(*this);
}

void View::sendEvent(sf::Event&event) {
    controller->handleEvents(event);
}
