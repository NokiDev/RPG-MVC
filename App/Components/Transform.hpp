//
// Created by bluedragonfly on 4/18/16.
//

#ifndef RPG_MVC_TRANSFORM_HPP
#define RPG_MVC_TRANSFORM_HPP

#include "Component.hpp"
#include <SFML/System/Vector2.hpp>

class Entity;

/**
 * @brief Component used for positioning entity in the window
 **/
class Transform : public Component {
public :
    /**
     * @brief default ctor
     * param Entity owner of the component
     * param sf::Vector2f position of the entity default set to (0,0)
     * param int depth of the entity for rendering layer default set to 1  @Warning Not used For now
     * param sf::Vector2i direction of the entity, wich direction the entity is facing default set to (0,0)
     * param sf::Vector2f rotation of the entity default set to (0,0)
     * param sf::Vector2f scale of the entity default set to (0,0)
     **/
    Transform(Entity *owner, sf::Vector2f position = sf::Vector2f(0.f, 0.0f), int depth = 1,
              sf::Vector2i direction = sf::Vector2i(0, 0), sf::Vector2f rotation = sf::Vector2f(0.0f, 0.0f),
              sf::Vector2f scale = sf::Vector2f(0.0f, 0.0f));

    /**
     * @brief Destructor
     **/
    ~Transform();

    /**
     * @brief update this component
     * @param sf::Time deltaTime, time between two frames default set to Zero
     **/
    virtual void update(sf::Time deltaTime = sf::Time::Zero) { };

    /**
     * @brief increment position with x and y params
     * @param float x value to increment
     * @param float y value to increment
     **/
    void move(float x, float y);

    /**
     * @var position of the entity
     **/
    sf::Vector2f position;
    /**
     * @var z depth of the entity
     * @warning Not Used For Now
     **/
    float z;
    /**
     * @var direction of the Entity, 8 directions, north-west, north-est, etc... default (0,0) mean standing
     **/
    sf::Vector2i direction;
    /**
     * @var rotation of the Entity
     **/
    sf::Vector2f rotation;
    /**
     * @var scale of the Entity
     **/
    sf::Vector2f scale;
};


#endif //RPG_MVC_TRANSFORM_HPP
