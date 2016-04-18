//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#ifndef RPG_MVC_BOXCOLLIDERCOMPONENT_HPP
#define RPG_MVC_BOXCOLLIDERCOMPONENT_HPP


#include <SFML/Graphics/Rect.hpp>

#include "Component.hpp"

class TriggerCollision;

class BoxColliderComponent : public Component{
public:
    BoxColliderComponent(Entity* owner, sf::Vector2u size, bool trigger = false, sf::Vector2f = sf::Vector2f(0.0f,0.0f));
    ~BoxColliderComponent();

    virtual void update(sf::Time deltaTime = sf::Time::Zero);
    void onCollision(BoxColliderComponent * collider);
    void onCollision(sf::FloatRect box);
    void onTriggerEnter(TriggerCollision & collision);
    void onTriggerStay(TriggerCollision & collision);
    void onTriggerExit(TriggerCollision & collision);

    sf::FloatRect getNextBox()const;
    sf::FloatRect getBox()const;
    sf::Vector2u getSize()const;
    sf::Vector2f getOffset()const;
    bool isMoving()const;
    bool isTrigger()const;


private:
    sf::Vector2u size;
    bool trigger;
    bool moving;
    sf::Vector2f offset;
    sf::FloatRect box;


};


#endif //RPG_MVC_BOXCOLLIDERCOMPONENT_HPP
