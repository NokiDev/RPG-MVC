//
// Created by Noki, Timothé Van Deputte on 18/04/2016.
//

#include "Damageable.hpp"

Damageable::Damageable(Entity *owner, float healthMax) : ScriptComponent(owner), healthMax(healthMax),
                                                         health(healthMax) {

}

Damageable::~Damageable() {

}

void Damageable::update(sf::Time deltaTime) {

}

void Damageable::takeDamage(float amount) {
    health -= amount;
    if (health < 0)
        health = 0;
    //Set Hurt State
}

bool Damageable::isDead() {
    return health <= 0;
}

bool Damageable::isHurt() {
    return damageTaken;
}

float Damageable::getHealth() {
    return health;
}

float Damageable::getHealthMax() {
    return healthMax;
}

void Damageable::heal(float amount) {
    health += amount;
    if (health > healthMax);
    {
        health = healthMax;
    }
}
