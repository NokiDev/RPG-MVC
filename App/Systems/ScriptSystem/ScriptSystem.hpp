//
// Created by bluedragonfly on 4/16/16.
//

#ifndef RPG_MVC_SCRIPTSYSTEM_HPP
#define RPG_MVC_SCRIPTSYSTEM_HPP


#include <App/Components/ScriptComponent.hpp>

class ScriptSystem {
public :
    static ScriptSystem* scriptSystem;
    ScriptSystem();
    ~ScriptSystem();

    void addNewScript(ScriptComponent* component);
    void delBox(ScriptComponent* component);


    void update(sf::Time deltaTime);

    void physicsUpdate();

private:
    std::set<ScriptComponent*> scripts;
};


#endif //RPG_MVC_SCRIPTSYSTEM_HPP
