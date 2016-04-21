//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#include "PauseMenuView.hpp"
#include <App/controllers/PauseMenuController.hpp>
#include <App/Helpers/Ressources.hpp>
#include "WindowManager.hpp"
#include "IViewComponent.hpp"

PauseMenuView::PauseMenuView(IController * controller) : View(controller){
    this->controller = controller;
    manager = WindowManager::get();
    background.setTexture(Ressources::Load("mainBackground.jpg"));
}

PauseMenuView::~PauseMenuView() {

}

void PauseMenuView::render(){
    manager->Window().setView(sf::View(sf::Vector2f(360,240), sf::Vector2f(720,480)));
    draw(background);
    manager->Window().setView(manager->Window().getDefaultView());
    for(auto component : components){
        component->draw(*this);
    }
}

void PauseMenuView::draw(const sf::Drawable &drawable, const sf::RenderStates &states) {
    manager->Window().draw(drawable, states);
}
