//
// Created by bluedragonfly on 3/29/16.
//

#include <App/App.hpp>
#include <App/views/ViewTextComponent.hpp>
#include <App/views/ViewSpriteComponent.hpp>
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

ViewSpriteComponent* IController::newSpriteRenderer(std::string textureName) {

    ViewSpriteComponent * spriteRenderer = new ViewSpriteComponent(textureName);
    view->addViewComponent(spriteRenderer);
    return spriteRenderer;
}

ViewTextComponent * IController::newTextRenderer(std::string text) {
    ViewTextComponent * textRenderer = new ViewTextComponent(text);
    view->addViewComponent(textRenderer);
    return textRenderer;
}
