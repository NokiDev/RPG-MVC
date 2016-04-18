//
// Created by bluedragonfly on 4/14/16.
//

#include <App/Components/Scripts/LiveTimerScript.hpp>
#include <App/Components/Scripts/Damageable.hpp>
#include "Laser.hpp"

Laser::Laser(IController *boss) : Entity(boss){
    position = sf::Vector2f(0.f, 0.f);
    velocity = sf::Vector2f(1.f, 0.f);
    direction = sf::Vector2f(0.f, 0.f);
    size = sf::Vector2u(10, 5);
    speed = 550;
    name = "Laser";
    spriteRenderer = boss->newSpriteRenderer("laser.png");
    addComponent(new BoxColliderComponent(this, sf::Vector2u(10, 5)));
    addComponent(new LiveTimerScript(this, 5.5f));
}

Laser::~Laser() {
    removeComponent<BoxColliderComponent>();
    removeComponent<LiveTimerScript>();
    delete spriteRenderer;
    //removeComponent<ViewSpriteComponent>();
}

void Laser::update(sf::Time deltaTime){
    velocity.x = speed * deltaTime.asSeconds()*direction.x;
    velocity.y = speed * deltaTime.asSeconds()*direction.y;
}

void Laser::physicsUpdate() {
    position += velocity;
    spriteRenderer->updatePosition(position);
}

void Laser::onCollision(BoxColliderComponent* collider) {
    Damageable* damageScript = collider->getOwner().getComponent<Damageable>();
    if(damageScript != nullptr){
        damageScript->takeDamage(1);
        boss->destroy(this);
    }
}
