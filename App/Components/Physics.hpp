//
// Created by bluedragonfly on 4/18/16.
//

#ifndef RPG_MVC_PHYSICS_HPP
#define RPG_MVC_PHYSICS_HPP

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include "Component.hpp"

/**
 * @brief Physics Component , allow entity to do physics stuff (actually only velocity is handled)
 */
class Physics : public Component {
public:
    /**
     * @brief Constructor
     * @param Entity* owner of this Component
     * @param bool freezeDirection of the entity Not Used for the Moment
    **/
    Physics(Entity *owner, bool freezeDirection = false);

    /**
     * @brief Destructor
    **/
    ~Physics();

    /**
     * @brief update Position
     * @param deltaTime Time between two frames
    **/
    void update(sf::Time deltaTime = sf::Time::Zero);

    /**
     * @brief Set velocity on the X axis
     * @param x value for the velocity on the X axis
    **/
    void setVelocityX(float x);

    /**
     * @brief Set velocity on the Y axis
     * @param y value for the velocity on the Y axis
    **/
    void setVelocityY(float y);

    /**
     * @brief Set velocity
     * @param vel value for the velocity
    **/
    void setVelocity(sf::Vector2f vel);

    /**
     * @brief Get the velocity vector
     * @return sf::Vector2f
    **/
    sf::Vector2f getVelocity();

private:
    /*
     * @var velocity, distance for 1 frame
     */
    sf::Vector2f m_Velocity;
    /**
     * @var freezeDirection
     */
    bool m_FreezeDirection;
};


#endif //RPG_MVC_PHYSICS_HPP
