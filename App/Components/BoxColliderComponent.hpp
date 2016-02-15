//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#ifndef RPG_MVC_BOXCOLLIDERCOMPONENT_HPP
#define RPG_MVC_BOXCOLLIDERCOMPONENT_HPP


#include <SFML/Graphics/Rect.hpp>
#include "Component.hpp"

class BoxColliderComponent : public Component{
public:
    BoxColliderComponent(Entity* owner, sf::Vector2u size, bool isTrigger = false, sf::Vector2f = sf::Vector2f(0.0f,0.0f));
    ~BoxColliderComponent();

    virtual void update(sf::Time deltaTime = sf::Time::Zero);

    sf::FloatRect getNextBox();

private:
    sf::Vector2u size;
    bool isTrigger;
    bool isMoving;
    sf::Vector2f offset;
    sf::FloatRect box;


};


#endif //RPG_MVC_BOXCOLLIDERCOMPONENT_HPP
