//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#ifndef RPG_MVC_COMPONENT_HPP
#define RPG_MVC_COMPONENT_HPP


#include <App/models/Entity.hpp>

class Component {
public:
    virtual ~Component() {};

    virtual void update(sf::Time deltaTime = sf::Time::Zero)=0;
    Entity& getOwner() const {
        return *owner;
    }

protected:

    Entity* owner;

};


#endif //RPG_MVC_COMPONENT_HPP
