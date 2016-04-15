//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#include <App/Helpers/Ressources.hpp>
#include "IngameView.hpp"
#include "IViewComponent.hpp"

IngameView::IngameView(IController* controller) : View(controller) {
    this->controller = controller;
    manager = WindowManager::get();
    background.setTexture(Ressources::Load("gameBackground.png"));
}

IngameView::~IngameView() {

}


void IngameView::render() {
    manager->Window().setView(sf::View(sf::Vector2f(360,240), sf::Vector2f(720,480)));
    draw(background);
    manager->Window().setView(manager->Window().getDefaultView());
    for(auto component : components)
    {
        component->draw(*this);
    }
}

void IngameView::draw(const sf::Drawable &drawable, const sf::RenderStates &states) {
    manager->Window().draw(drawable, states);
}

