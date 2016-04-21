//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#include "MainMenuView.hpp"
#include <App/controllers/MainMenuController.hpp>
#include <App/Helpers/Ressources.hpp>
#include "WindowManager.hpp"
#include "IViewComponent.hpp"

MainMenuView::MainMenuView(IController *controller) : View(controller) {
    this->controller = controller;
    manager = WindowManager::get();
    background.setTexture(Ressources::Load("mainBackground.jpg"));
    title = new ViewTextComponent("Space MVC");
}

MainMenuView::~MainMenuView() {
    components.clear();
}

void MainMenuView::render() {
    manager->Window().setView(sf::View(sf::Vector2f(360, 240), sf::Vector2f(720, 480)));
    draw(background);
    manager->Window().setView(manager->Window().getDefaultView());
    for (auto component : components) {
        component->draw(*this);
    }
    title->updatePosition(sf::Vector2f(getSize().x/2-110, getSize().y/4-100));
    title->draw(*this);
}

void MainMenuView::draw(const sf::Drawable &drawable, const sf::RenderStates &states) {
    manager->Window().draw(drawable, states);
}
