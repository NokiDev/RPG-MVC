//
// Created by bluedragonfly on 4/12/16.
//

#ifndef RPG_MVC_VIEWTEXTCOMPONENT_HPP
#define RPG_MVC_VIEWTEXTCOMPONENT_HPP

#include <SFML/Graphics/Text.hpp>
#include "ViewComponent.hpp"

class View;
class ViewTextComponent : public ViewComponent{
public:
    ViewTextComponent(std::string text);

    void draw(View & view);
    void updatePosition(sf::Vector2f position);


protected:
    sf::Text text;
    sf::Font font;
};

#endif //RPG_MVC_VIEWTEXTCOMPONENT_HPP
