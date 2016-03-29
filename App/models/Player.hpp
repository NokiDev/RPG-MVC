//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_PLAYER_HPP
#define RPG_MVC_PLAYER_HPP

#include "View.hpp"
#include "Entity.hpp"

class RenderComponent;
class Player : public Entity {
public :
    Player();
    ~Player();
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
    virtual void onCollision();

    virtual void render(View & view);
    /**
     * @brief Update the entity each frame
     * @params time between two frames
    **/

    sf::Vector2f getSpriteSize();


protected:
    sf::Sprite sprite;
    //RenderComponent* render;
};


#endif //RPG_MVC_PLAYER_HPP
