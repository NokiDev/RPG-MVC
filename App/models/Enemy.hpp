//
// Created by bluedragonfly on 4/17/16.
//

#ifndef RPG_MVC_ENNEMYFACTORY_HPP
#define RPG_MVC_ENNEMYFACTORY_HPP


#include "Entity.hpp"

class ViewSpriteComponent;
class Enemy: public Entity{

public :
    Enemy(IController* boss);
    ~Enemy();
    /**
         * @brief Update the entity each frame
         * @params time between two frames
        **/
    virtual void update(sf::Time deltaTime = sf::Time::Zero);

    /**
     * @brief Update Physics velocity and position
     */
    virtual void physicsUpdate();

    /**
     * @brief Behaviour to adopt when entering on collision
     */
    virtual void onCollision(BoxColliderComponent * collider);
    /**
     * @brief Update the entity each frame
     * @params time between two frames
    **/



private :
    ViewSpriteComponent * spriteRenderer;


};


#endif //RPG_MVC_ENNEMYFACTORY_HPP
