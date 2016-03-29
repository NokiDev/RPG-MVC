//
// Created by bluedragonfly on 3/22/16.
//

#ifndef RPG_MVC_MAP_HPP
#define RPG_MVC_MAP_HPP

#include <string>
#include <App/views/IView.hpp>
#include "Entity.hpp"
#include "Tile.hpp"
#include "Player.hpp"


/*
 * @brief Represent the current map,
 *
 *
 */
class Map {
public :
    Map(Player* player);
    ~Map();

    void update();
    void updatePhysics();
    void checkCollisions();
    void load(std::string mapName);
    void instantiate(Entity*entity);
    void render(IView & view);

private:

    Player* thePlayer;
    std::vector<Entity*> entities; //Represent all entities in the Map
    std::vector<Tile*> tiles; //Represent all tiles of the Map

};


#endif //RPG_MVC_MAP_HPP
