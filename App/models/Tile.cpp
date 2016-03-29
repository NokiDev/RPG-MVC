//
// Created by bluedragonfly on 3/22/16.
//

#include "Tile.hpp"

Tile::Tile(std::string texture, float x, float y, float z, sf::FloatRect box, sf::Vector2f offset, bool isTrigger) {
    position = sf::Vector2f(x, y);
    this->z = z;
}

Tile::~Tile() {

}

void Tile::render(IView &view) {

}
