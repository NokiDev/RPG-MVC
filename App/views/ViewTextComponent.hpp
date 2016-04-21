//
// Created by bluedragonfly on 4/12/16.
//

#ifndef RPG_MVC_VIEWTEXTCOMPONENT_HPP
#define RPG_MVC_VIEWTEXTCOMPONENT_HPP

#include "IViewComponent.hpp"
#include <SFML/Graphics/Text.hpp>

class ViewTextComponent : public IViewComponent {
public:
    ViewTextComponent(std::string text);

    ~ViewTextComponent() { };

    virtual void draw(View &view);

    void updatePosition(sf::Vector2f position);

    void updateText(std::string text);


protected:
    sf::Text text;
    sf::Font font;
};

#endif //RPG_MVC_VIEWTEXTCOMPONENT_HPP
