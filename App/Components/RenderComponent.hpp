//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#ifndef RPG_MVC_RENDERCOMPONENT_HPP
#define RPG_MVC_RENDERCOMPONENT_HPP


#include <SFML/Graphics.hpp>
#include "Component.hpp"

class RenderComponent : public Component {

public:
    RenderComponent(Entity* owner, std::string textureName);
    ~RenderComponent();

    virtual void update(sf::Time deltaTime = sf::Time::Zero);
    void draw(sf::RenderWindow & window);

protected:
    sf::Sprite sprite;
};


#endif //RPG_MVC_RENDERCOMPONENT_HPP
