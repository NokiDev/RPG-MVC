//
// Created by bluedragonfly on 4/16/16.
//

#ifndef RPG_MVC_SCRIPTSYSTEM_HPP
#define RPG_MVC_SCRIPTSYSTEM_HPP


#include <App/Components/ScriptComponent.hpp>

/**
 * @brief Ssystem, composed with, Script Components and updates them
 **/
class ScriptSystem {
public :
    /**
     * @brief static reference to scriptSystem
     **/
    static ScriptSystem *scriptSystem;

    /**
     * @brief default ctor
     **/
    ScriptSystem();

    /**
     * @brief dtor
     **/
    ~ScriptSystem();

    /**
     * @brief add a new component in the system
     * @param component to add
     **/
    void addNewScript(ScriptComponent *component);

    /**
     * @brief remove component in the system
     * @param component to remove
     **/
    void delBox(ScriptComponent *component);

    /**
     * @brief update components each frame
     * @param sf::Time deltaTime time between two frames
     **/
    void update(sf::Time deltaTime);

    /**
     * @brief call physic Update for all scriptComponents
     **/
    void physicsUpdate();

private:

    /**
    * @brief List of script Components
    **/
    std::set<ScriptComponent *> scripts;
};


#endif //RPG_MVC_SCRIPTSYSTEM_HPP
