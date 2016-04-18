//
// Created by Noki, Timothé Van Deputte on 18/04/2016.
//

#ifndef RPG_MVC_DAMAGEABLE_HPP
#define RPG_MVC_DAMAGEABLE_HPP

#include "ScriptComponent.hpp"

class Damageable : public ScriptComponent {
public:
    Damageable(Entity* owner, float healthMax);
    ~Damageable();

    virtual void update(sf::Time deltaTime);

    void takeDamage(float amount);
    void heal(float amount);

    bool isDead();
    bool isHurt();
    float getHealth();
    float getHealthMax();

private:

    float health;
    float healthMax;
    float invincibleTime;

    float timer;
    bool damageTaken;


};


#endif //RPG_MVC_DAMAGEABLE_HPP
