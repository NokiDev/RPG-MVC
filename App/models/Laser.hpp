//
// Created by bluedragonfly on 4/14/16.
//

#ifndef RPG_MVC_LASER_HPP
#define RPG_MVC_LASER_HPP


#include <App/controllers/IController.hpp>
#include <App/Components/BoxColliderComponent.hpp>
#include "Entity.hpp"

class Laser : public Entity {
public :
    Laser(IController *boss, std::string attackLayer);

    ~Laser();

    virtual void update(sf::Time deltaTime);

private:
    IController *boss;
    ViewSpriteComponent *spriteRenderer;
};


#endif //RPG_MVC_LASER_HPP
