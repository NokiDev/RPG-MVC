//
// Created by bluedragonfly on 4/18/16.
//

#ifndef RPG_MVC_ENEMYSCRIPT_HPP
#define RPG_MVC_ENEMYSCRIPT_HPP


#include <SFML/System/Time.hpp>
#include <App/Components/ScriptComponent.hpp>


class Damageable;
class EnemyScript : public ScriptComponent {
public :
    EnemyScript(Entity* owner);
    ~EnemyScript();

    virtual void update(sf::Time deltaTime);


private:

};


#endif //RPG_MVC_ENEMYSCRIPT_HPP
