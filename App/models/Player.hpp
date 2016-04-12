//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_PLAYER_HPP
#define RPG_MVC_PLAYER_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <App/views/ViewSpriteComponent.hpp>
#include <App/controllers/IController.hpp>
#include "Entity.hpp"

class View;
class RenderComponent;
class Player : public Entity {
public :
    Player(IController* boss);
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
    /**
     * @brief Update the entity each frame
     * @params time between two frames
    **/

    sf::Vector2f getSpriteSize();


protected:
    IController* boss;
    ViewSpriteComponent* spriteRenderer;
    //RenderComponent* render;
};


#endif //RPG_MVC_PLAYER_HPP
