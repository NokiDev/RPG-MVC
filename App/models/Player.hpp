//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_PLAYER_HPP
#define RPG_MVC_PLAYER_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <App/views/ViewSpriteComponent.hpp>
#include <App/Components/BoxColliderComponent.hpp>
#include <App/Components/EventHandlerComponent.hpp>
#include "Entity.hpp"

class View;
class EventsHandler;
class RenderComponent;
class Player : public Entity {
public :
    Player(IController* boss);
    ~Player();

    virtual void update(sf::Time deltaTime);

protected:
    ViewSpriteComponent* spriteRenderer;
    EventHandlerComponent * eventHandler;
};


#endif //RPG_MVC_PLAYER_HPP
