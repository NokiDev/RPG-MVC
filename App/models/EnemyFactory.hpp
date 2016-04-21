//
// Created by bluedragonfly on 4/17/16.
//

#ifndef RPG_MVC_ENEMY_HPP
#define RPG_MVC_ENEMY_HPP

#include "Entity.hpp"

class EnemyFactory : public Entity {
public :
    EnemyFactory(IController *boss, float delayForFirstLaunch, float spawnTime);

    ~EnemyFactory();
};


#endif //RPG_MVC_ENEMY_HPP
