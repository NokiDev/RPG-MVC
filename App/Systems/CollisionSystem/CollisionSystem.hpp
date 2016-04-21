//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#ifndef RPG_MVC_COLLISIONSYSTEM_HPP
#define RPG_MVC_COLLISIONSYSTEM_HPP


#include <set>
#include <SFML/System/Time.hpp>

class BoxColliderComponent;

class TriggerCollision;

/**
 * @brief Regroup all BoxCollider Components, in the System
 **/
class CollisionSystem {
public :
    /**
     * @brief static reference to this
     **/
    static CollisionSystem *collisionSystem;

    /**
     * @brief default ctor
     */
    CollisionSystem();

    /**
     * @brief dtor
     **/
    ~CollisionSystem();

    /**
    * @brief add a new component in the system
    * @param component to add
    **/
    void addBoxCollider(BoxColliderComponent *boxCollider);

    /**
     * @brief add a moving boxCollider in the system
     * @param component to add
     **/
    void addMovingBoxCollider(BoxColliderComponent *boxCollider);

    /**
     * @brief remove component in the system
     * @param component to remove
     **/
    void delBoxCollider(BoxColliderComponent *boxCollider);

    /**
     * @brief checkCollisions between moving boxes and all colliders with test for the distance etc. .. . .
     **/
    void checkCollisions();

    /**
     * @brief update components eachFrames
     * @param sf::Time deltaTime, time between two frames
     **/
    void updateComponents(sf::Time);

private:

    std::set<BoxColliderComponent *> boxColliders;
    std::set<BoxColliderComponent *> movingColliders;
    std::set<TriggerCollision *> triggerCollisions;
};


#endif //RPG_MVC_COLLISIONSYSTEM_HPP
