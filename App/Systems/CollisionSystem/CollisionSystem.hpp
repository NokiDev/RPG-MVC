//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#ifndef RPG_MVC_COLLISIONSYSTEM_HPP
#define RPG_MVC_COLLISIONSYSTEM_HPP


#include <set>
#include <App/Components/BoxColliderComponent.hpp>

class TriggerCollision
{
public:
    TriggerCollision(BoxColliderComponent* trigger, BoxColliderComponent* collider);

    bool collExist(BoxColliderComponent* trigger, BoxColliderComponent* collider);
    bool isCollide();

    BoxColliderComponent& getTrigger();
    BoxColliderComponent& getCollider();

private:
    BoxColliderComponent* trigger;
    BoxColliderComponent* collider;
};

class CollisionSystem {
public :
    static CollisionSystem *collisionSystem;
    CollisionSystem();
    ~CollisionSystem();

    void addBoxCollider(BoxColliderComponent* boxCollider);
    void addMovingBoxCollider(BoxColliderComponent* boxCollider);
    void delBoxCollider(BoxColliderComponent* boxCollider);

    void checkCollisions();

private:

    std::set<BoxColliderComponent*> boxColliders;
    std::set<BoxColliderComponent*> movingColliders;
    std::set<TriggerCollision*> triggerCollisions;
};


#endif //RPG_MVC_COLLISIONSYSTEM_HPP
