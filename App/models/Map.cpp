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

}

void Map::render(IView &view) {
    for(auto tile : tiles){
        tile->render(view);
    }
    for(auto entity : entities) {
        //entity->render(view);
    }
    thePlayer->render(view);
}

void Map::update() {

}

void Map::updatePhysics() {

}

void Map::checkCollisions() {

}
