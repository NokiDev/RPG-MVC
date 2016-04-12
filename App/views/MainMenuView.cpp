//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#include "MainMenuView.hpp"
#include "WindowManager.hpp"

MainMenuView::MainMenuView(IController * controller) : View(controller){
    this->controller = controller;
    manager = WindowManager::get();
}

MainMenuView::~MainMenuView() {


}


void MainMenuView::render(){
    for(ViewComponent* component : components){
        component->draw(*this);
    }
}

void MainMenuView::draw(const sf::Drawable &drawable, const sf::RenderStates &states) {
    manager->Window().draw(drawable, states);
}
