//
// Created by bluedragonfly on 4/18/16.
//

#ifndef RPG_MVC_PHYSICS_HPP
#define RPG_MVC_PHYSICS_HPP

#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include "Component.hpp"

class Physics : public Component{
public:
    /**
     * @brief Constructor
     * @param owner Owner of this Component
    **/
    Physics(Entity* owner, bool freezeDirection = false);
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
    sf::Vector2f m_Velocity;///Velocity (distance for 1 frame)
    bool m_FreezeDirection;
};


#endif //RPG_MVC_PHYSICS_HPP
