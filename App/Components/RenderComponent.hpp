//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#ifndef RPG_MVC_RENDERCOMPONENT_HPP
#define RPG_MVC_RENDERCOMPONENT_HPP


#include <SFML/Graphics.hpp>
#include <App/views/ViewComponent.hpp>
#include "Component.hpp"

class RenderComponent : public Component {

public:

    struct depthCompare {
        /**
         * @brief Overload () operator for comparing SpriteRenderers
         * @param lSprite left side SpriteRenderer var
         * @param rSprite right side SpriteRenderer var
        **/
        bool operator() (const RenderComponent* lSprite, const RenderComponent* rSprite) const
        {
            return lSprite->sprite.getPosition().y > rSprite->sprite.getPosition().y;
        }
    };

    RenderComponent(Entity* owner, std::string textureName);
    ~RenderComponent();

    virtual void update(sf::Time deltaTime = sf::Time::Zero);
    virtual void draw(sf::RenderWindow & window);
    virtual void rotate(int scaley, int scalex = -1);

protected:
    sf::Sprite sprite;
    ViewComponent* viewComponent;
};


#endif //RPG_MVC_RENDERCOMPONENT_HPP
