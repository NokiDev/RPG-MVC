//
// Created by bluedragonfly on 4/18/16.
//

#include <App/Systems/PhysicsSystem/PhysicsSystem.hpp>
#include "Physics.hpp"
#include "Transform.hpp"
#include "Entity.hpp"
#include "CollisionSystem.hpp"
#include "BoxColliderComponent.hpp"

Physics::Physics(Entity* owner, bool freezeDirection) : m_Velocity(sf::Vector2f(0.0f,0.0f)), m_FreezeDirection(freezeDirection)
{
    this->owner = owner;
    PhysicsSystem::physicsSystem->addPhysics(this);
}

Physics::~Physics()
{
    PhysicsSystem::physicsSystem->delPhysics(this);
}

void Physics::update(sf::Time deltaTime)
{
    Transform * t = owner->getComponent<Transform>();
    t->move(m_Velocity.x, m_Velocity.y);

    m_Velocity = sf::Vector2f(0.f,0.f);
}


void Physics::setVelocityX(float x)
{
    setVelocity(sf::Vector2f(x, m_Velocity.y));
}

void Physics::setVelocityY(float y)
{
    setVelocity(sf::Vector2f(m_Velocity.x, y));
}

void Physics::setVelocity(sf::Vector2f x)
{
    m_Velocity = x;
    PhysicsSystem::physicsSystem->addMovingPhysics(this);
    CollisionSystem::collisionSystem->addMovingBoxCollider(owner->getComponent<BoxColliderComponent>());
}

sf::Vector2f Physics::getVelocity()
{
    return m_Velocity;
}
