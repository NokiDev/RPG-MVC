//
// Created by bluedragonfly on 4/14/16.
//

#include <App/Components/Scripts/LiveTimerScript.hpp>
#include <App/Components/Scripts/Damageable.hpp>
#include <App/Components/Physics.hpp>
#include <App/Components/Scripts/LaserScript.hpp>
#include <App/Components/Transform.hpp>
#include "Laser.hpp"

Laser::Laser(IController *boss, std::string attackLayer) : Entity(boss){
    size = sf::Vector2u(10, 5);
    name = "Laser";
    this->boss = boss;
    spriteRenderer = boss->newSpriteRenderer("laser.png");

    ///Need To order Components
    addComponent(new BoxColliderComponent(this, sf::Vector2u(10, 5)));
    addComponent(new Physics(this));

    ///Need To order Scripts
    addScript(new LaserScript(this,attackLayer));
    addScript(new LiveTimerScript(this, 5.5f));
}

Laser::~Laser() {
    removeComponent<Physics>();
    removeComponent<BoxColliderComponent>();

    removeScript<LiveTimerScript>();
    removeScript<LaserScript>();

    delete spriteRenderer;
}

void Laser::update(sf::Time deltaTime) {
    Transform * t = getComponent<Transform>();
    spriteRenderer->updatePosition(t->position);
}
