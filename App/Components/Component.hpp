//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#ifndef RPG_MVC_COMPONENT_HPP
#define RPG_MVC_COMPONENT_HPP

#include <SFML/System/Time.hpp>

class Entity;

/**
 * @brief basic class for all components
 **/
class Component {
public:
    virtual ~Component() { };

    /**
     * @brief update component
     * @param sf::Time deltaTime timeBetween two frames
     **/
    virtual void update(sf::Time deltaTime = sf::Time::Zero) = 0;

    /**
     * @brief getOwner
     * @return Entity & owner
     **/
    Entity &getOwner() const {
        return *owner;
    }

protected:
    /**
     * @var owner of the component
     **/
    Entity *owner;

};


#endif //RPG_MVC_COMPONENT_HPP
