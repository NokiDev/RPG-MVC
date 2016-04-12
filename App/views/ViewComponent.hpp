//
// Created by bluedragonfly on 3/22/16.
//

#ifndef RPG_MVC_IVIEWCOMPONENT_HPP
#define RPG_MVC_IVIEWCOMPONENT_HPP

#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <App/models/Entity.hpp>

class View;
class ViewComponent {

public:
    ViewComponent();
    ViewComponent(std::string textureName);

    virtual void draw(View & view);
    virtual void updatePosition(sf::Vector2f position);
    virtual void updateRect(sf::IntRect textRect);


protected:
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif //RPG_MVC_IVIEWCOMPONENT_HPP
