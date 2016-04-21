//
// Created by bluedragonfly on 4/21/16.
//

#include "GameOverView.hpp"
#include "WindowManager.hpp"
#include "IViewComponent.hpp"
#include "ViewTextComponent.hpp"

GameOverView::GameOverView(IController *controller) : View(controller) {
    this->controller = controller;
    manager = WindowManager::get();
    ViewTextComponent *t = new ViewTextComponent("GAME OVER !");
    t->updatePosition(sf::Vector2f(getSize().x / 2 - 50, getSize().y / 2 - 70));
    addViewComponent(t);
    t = new ViewTextComponent("Press Enter ...");
    t->updatePosition(sf::Vector2f(getSize().x / 2 - 70, getSize().y / 2 + 25));
    addViewComponent(t);
    background.create(getSize().x, getSize().y, sf::Color(125, 125, 125, 125));
    texture.loadFromImage(background);
    sprite.setTexture(texture);
}

GameOverView::~GameOverView() {

}

void GameOverView::render() {

    manager->Window().draw(sprite);
    for (auto component : components) {
        component->draw(*this);
    }
}

void GameOverView::draw(const sf::Drawable &drawable, const sf::RenderStates &states) {
    manager->Window().draw(drawable, states);
}





