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

    sf::Vector2f getPosition() const {
        return position;
    }

    sf::Vector2f getVelocity() const {
        return velocity;
    }

    int getSpeed() const{
        return speed;
    }

    float getZ()const{
        return z;
    }

    int getId() const{
        return id;
    }

protected :
    Entity() : id(nextId++){};
    sf::Vector2f position;
    float z; ///Depth for render ===NOT USED===
    sf::Vector2f velocity;
    int speed;
    std::string name;
    const int id;
    static int nextId;


};

#endif //RPG_MVC_ENTITY_HPP
