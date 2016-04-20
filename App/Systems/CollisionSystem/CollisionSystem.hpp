//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#ifndef RPG_MVC_COLLISIONSYSTEM_HPP
#define RPG_MVC_COLLISIONSYSTEM_HPP


#include <set>
#include <SFML/System/Time.hpp>

class BoxColliderComponent;
class TriggerCollision;
class CollisionSystem {
public :
    static CollisionSystem *collisionSystem;
    CollisionSystem();
    ~CollisionSystem();

    void addBoxCollider(BoxColliderComponent* boxCollider);
    void addMovingBoxCollider(BoxColliderComponent* boxCollider);
    void delBoxCollider(BoxColliderComponent* boxCollider);

    void checkCollisions();

    void updateComponents(sf::Time);

private:

    std::set<BoxColliderComponent*> boxColliders;
    std::set<BoxColliderComponent*> movingColliders;
    std::set<TriggerCollision*> triggerCollisions;
};


#endif //RPG_MVC_COLLISIONSYSTEM_HPP
