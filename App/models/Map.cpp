//
// Created by bluedragonfly on 3/22/16.
//

#include "Map.hpp"


Map::Map(Player* player) {
    thePlayer = player;
}

Map::~Map() {

}


void Map::load(std::string mapName) {
    //Make A load function for loading MAp, XMLDataHelper.loadMap();
}

void Map::instantiate(Entity *entity) {
    entities.push_back(entity);
}

void Map::update(sf::Time time1) {

}

void Map::updatePhysics() {

}

void Map::checkCollisions() {

}
