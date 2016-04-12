//
// Created by bluedragonfly on 4/12/16.
//

#ifndef RPG_MVC_VIEWSPRITECOMPONENT_HPP
#define RPG_MVC_VIEWSPRITECOMPONENT_HPP

#include "IViewComponent.hpp"

class ViewSpriteComponent : public IViewComponent{

public :
    ViewSpriteComponent(std::string textureName);

    virtual void draw(View & view);
    void updatePosition(sf::Vector2f position);
    void updateRect(sf::IntRect textRect);


protected:
    sf::Texture texture;
    sf::Sprite sprite;

};


#endif //RPG_MVC_VIEWSPRITECOMPONENT_HPP
