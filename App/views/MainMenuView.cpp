//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#include "MainMenuView.hpp"
#include <App/controllers/MainMenuController.hpp>
#include <App/models/Ressources.hpp>
#include "WindowManager.hpp"
#include "IViewComponent.hpp"

MainMenuView::MainMenuView(IController * controller) : View(controller){
    this->controller = controller;
    manager = WindowManager::get();
    background.setTexture(Ressources::Load("mainBackground.jpg"));
}

MainMenuView::~MainMenuView() {

}

void MainMenuView::render(){
    draw(background);
    for(IViewComponent* component : components){
        component->draw(*this);
    }
}

void MainMenuView::draw(const sf::Drawable &drawable, const sf::RenderStates &states) {
    manager->Window().draw(drawable, states);
}
