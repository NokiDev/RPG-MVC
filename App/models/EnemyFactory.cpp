//
// Created by bluedragonfly on 4/17/16.
//

#include <App/Components/Scripts/FactoryScript.hpp>
#include "EnemyFactory.hpp"

EnemyFactory::EnemyFactory(IController *boss, float delayForFirstLaunch, float spawnTime) : Entity(boss) {

    addScript(new FactoryScript(this, delayForFirstLaunch, spawnTime));
}

EnemyFactory::~EnemyFactory() {
    removeScript<FactoryScript>();
}
