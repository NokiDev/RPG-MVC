//
// Created by bluedragonfly on 3/29/16.
//

#include <App/App.hpp>
#include "IController.hpp"
#include "View.hpp"


void IController::askForEvents(){
    view->askForEvent();
}

void IController::askForRender(){
    view->render();
}

void IController::handleEvents(sf::Event &event) {
    if(event.type == sf::Event::Closed)
    {
        App::get()->close();
    }
}

View *IController::getView() {
    return view;
}
