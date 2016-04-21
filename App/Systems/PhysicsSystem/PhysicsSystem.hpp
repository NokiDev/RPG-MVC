//
// Created by bluedragonfly on 4/18/16.
//

#ifndef RPG_MVC_PHYSICSSYSTEM_HPP
#define RPG_MVC_PHYSICSSYSTEM_HPP

#include <SFML/System/Time.hpp>
#include <set>

class Physics;

/**
 * @brief Regroup all physics components in the system, that may update them
 **/
class PhysicsSystem {
public:
    static PhysicsSystem *physicsSystem;///Reference to this
    /**
     * @brief Constructor
    **/
    PhysicsSystem();

    /**
     * @brief Destructor
    **/
    virtual ~PhysicsSystem();

    /**
     * @brief Add a Physics Component to Manage
     * @param physic Physic Component to add
    **/
    void addPhysics(Physics *physic);

    void delPhysics(Physics *physic);

    /**
     * @brief Add a moving physic component to manage
     * @param physic Moving Physic Component to add
    **/
    void addMovingPhysics(Physics *physic);

    /**
     * @brief Update Physics Components
    **/
    void updateComponents(sf::Time deltaTime = sf::Time::Zero);

private:
    std::set<Physics *> physicsComponents;
    ///List of all physics components
    std::set<Physics *> movingComponents;///List of all moving Physics Components
};


#endif //RPG_MVC_PHYSICSSYSTEM_HPP
