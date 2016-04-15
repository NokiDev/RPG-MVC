//
// Created by bluedragonfly on 3/22/16.
//

#ifndef RPG_MVC_MAP_HPP
#define RPG_MVC_MAP_HPP

#include <string>
#include "View.hpp"
#include "Entity.hpp"
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

    void update(sf::Time time1);
    void updatePhysics();
    void checkCollisions();
    void load(std::string mapName);
    void instantiate(Entity*entity);

private:

    Player* thePlayer;
    std::vector<Entity*> entities; //Represent all entities in the Map

};


#endif //RPG_MVC_MAP_HPP
