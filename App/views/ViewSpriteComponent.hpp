//
// Created by bluedragonfly on 4/12/16.
//

#ifndef RPG_MVC_VIEWSPRITECOMPONENT_HPP
#define RPG_MVC_VIEWSPRITECOMPONENT_HPP

#include "IViewComponent.hpp"

class ViewSpriteComponent : public IViewComponent {

public :
    ViewSpriteComponent(std::string textureName);

    ~ViewSpriteComponent();

    virtual void update(sf::Time deltaTime);

    virtual void draw(View &view);

    void updatePosition(sf::Vector2f position);

    void updateRect(sf::IntRect textRect);

    void updateColor(sf::Color color);


protected:
    sf::Texture texture;
    sf::Sprite sprite;

};


#endif //RPG_MVC_VIEWSPRITECOMPONENT_HPP
