//
// Created by bluedragonfly on 4/14/16.
//

#ifndef RPG_MVC_LASER_HPP
#define RPG_MVC_LASER_HPP


#include <App/controllers/IController.hpp>
#include <App/Components/BoxColliderComponent.hpp>
#include "Entity.hpp"

class Laser : public Entity{
    public :
        Laser(IController*boss);
        ~Laser();
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
    private:
        IController* boss;
        ViewSpriteComponent * spriteRenderer;
        BoxColliderComponent * boxColliderComponent;
        sf::Time timeToLive;
};


#endif //RPG_MVC_LASER_HPP
