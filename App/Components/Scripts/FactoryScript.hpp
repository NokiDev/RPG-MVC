//
// Created by Noki, Timothé Van Deputte on 20/04/2016.
//

#ifndef RPG_MVC_FACTORYSCIPT_HPP
#define RPG_MVC_FACTORYSCIPT_HPP


#include <App/Components/ScriptComponent.hpp>

class FactoryScript : public ScriptComponent {
public :

    FactoryScript(Entity *owner, float delayForFirstLaunch, float spawnTime);

    ~FactoryScript();

    virtual void update(sf::Time deltaTime);

    virtual void physicsUpdate();

private:

    float spawnTimer;
    float delayForFirstLaunch;
    bool isFirstLaunch;
    float timer;


};


#endif //RPG_MVC_FACTORYSCIPT_HPP
