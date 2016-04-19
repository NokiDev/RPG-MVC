//
// Created by bluedragonfly on 4/16/16.
//

#include "ScriptSystem.hpp"

ScriptSystem* ScriptSystem::scriptSystem;

ScriptSystem::ScriptSystem() {
    if(scriptSystem == nullptr){
        scriptSystem = this;
    }
    else
    {
        std::cerr<<"WARNING SINGLETON INSTANCE ALREADY EXIST FIX THIS! "<<std::endl;
    }
}

ScriptSystem::~ScriptSystem() {

}

void ScriptSystem::update(sf::Time deltaTime) {
    for(auto script : scripts){
        script->update(deltaTime);
    }
}

void ScriptSystem::physicsUpdate() {
    for(auto script : scripts){

        script->physicsUpdate();
    }
}

void ScriptSystem::addNewScript(ScriptComponent *component) {
    scripts.insert(component);
}

void ScriptSystem::delBox(ScriptComponent *component) {
    scripts.erase(component);

}


