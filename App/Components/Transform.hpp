//
// Created by bluedragonfly on 4/18/16.
//

#ifndef RPG_MVC_TRANSFORM_HPP
#define RPG_MVC_TRANSFORM_HPP

#include "Component.hpp"
#include <SFML/System/Vector2.hpp>

class Entity;
class Transform : public Component{
public :
    Transform(Entity* owner, sf::Vector2f position = sf::Vector2f(0.f,0.0f), int depth = 1, sf::Vector2i direction = sf::Vector2i(0,0), sf::Vector2f rotation = sf::Vector2f(0.0f,0.0f), sf::Vector2f scale = sf::Vector2f(0.0f,0.0f));
    /**
     * @brief Destructor
    **/
    ~Transform();

    virtual void update(sf::Time deltaTime = sf::Time::Zero){};

    void move(float x, float y);

    sf::Vector2f position;
    float z;//Z is used for depth render
    sf::Vector2i direction; // 8directions, north-west, north-est, etc... default (0,0) mean standing
    sf::Vector2f rotation; //
    sf::Vector2f scale;
};


#endif //RPG_MVC_TRANSFORM_HPP
