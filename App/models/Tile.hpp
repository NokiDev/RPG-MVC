//
// Created by bluedragonfly on 3/22/16.
//

#ifndef RPG_MVC_TILE_HPP
#define RPG_MVC_TILE_HPP

#include <SFML/Graphics/Rect.hpp>
#include <App/views/IView.hpp>
#include "Entity.hpp"


class Tile : public Entity{
public:
    Tile(std::string texture, float x, float y, float z, sf::FloatRect box = sf::FloatRect(0.f,0.f, 32,32), sf::Vector2f offset = sf::Vector2f(0.f,0.f), bool isTrigger = true);
    ~Tile();

    void render(IView & view);
private:
};


#endif //RPG_MVC_TILE_HPP
