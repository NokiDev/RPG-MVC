//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_ENTITY_HPP
#define RPG_MVC_ENTITY_HPP

#include <SFML/System.hpp>

class Entity {
public :

    virtual ~Entity() {};

    /**
     * @brief Update the entity each frame
     * @params time between two frames
    **/
    virtual void update(sf::Time deltaTime = sf::Time::Zero) = 0;

    /**
     * @brief Update Physics velocity and position
     */
    virtual void physicsUpdate() = 0;

    /**
     * @brief Behaviour to adopt when entering on collision
     */
    virtual void onCollision() = 0;

    sf::Vector2f position;
protected :
    //sf::Vector2f position;
    sf::Vector2f velocity;


};


#endif //RPG_MVC_ENTITY_HPP
