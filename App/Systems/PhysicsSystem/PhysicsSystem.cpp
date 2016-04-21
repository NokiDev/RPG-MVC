#include "PhysicsSystem.hpp"
#include <iostream>
#include "../Components/Physics.hpp"

#include "Entity.hpp"

PhysicsSystem *PhysicsSystem::physicsSystem;

PhysicsSystem::PhysicsSystem() {
    if (physicsSystem != nullptr) {
        std::cout << "WARNING PhysicsSystem already Exist !!" << std::endl;
        delete this;
    }
    else {
        physicsSystem = this;
    }
}

PhysicsSystem::~PhysicsSystem() {
    PhysicsSystem::physicsSystem = nullptr;
}

void PhysicsSystem::addPhysics(Physics *physic) {
    physicsComponents.insert(physic);
}

void PhysicsSystem::delPhysics(Physics *physic) {
    physicsComponents.erase(physic);
}

void PhysicsSystem::addMovingPhysics(Physics *physic) {
    movingComponents.insert(physic);
}

void PhysicsSystem::updateComponents(sf::Time deltaTime) {
    if (movingComponents.size() > 0) {
        for (Physics *physic : movingComponents) {
            physic->update();
            //physic->Move();
        }
        movingComponents.clear();
    }
}
