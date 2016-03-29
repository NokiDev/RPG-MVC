//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#include "IngameView.hpp"
#include "WindowManager.hpp"

IngameView::IngameView() {
    manager = WindowManager::get();
}

IngameView::~IngameView() {

}

void IngameView::render() const {
    for(auto component : components)
    {
        //component->draw();
    }
    manager->display();
}

void IngameView::draw(const sf::Drawable &drawable, const sf::RenderStates &states) {
    manager->Window().draw(drawable, states);
}
