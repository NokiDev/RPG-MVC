//
// Created by bluedragonfly on 3/22/16.
//

#ifndef RPG_MVC_IVIEWCOMPONENT_HPP
#define RPG_MVC_IVIEWCOMPONENT_HPP

#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <App/models/Entity.hpp>

class IViewComponent {

public:

protected:
    Entity* owner;
    std::string textureName;
    sf::Sprite sprite;
};


#endif //RPG_MVC_IVIEWCOMPONENT_HPP
