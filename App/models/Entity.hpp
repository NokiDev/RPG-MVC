//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_ENTITY_HPP
#define RPG_MVC_ENTITY_HPP

#include <SFML/System.hpp>
#include <map>
#include <typeinfo>
#include <iostream>
#include <App/Components/Component.hpp>


class IController;
class BoxColliderComponent;
class Component;
class ScriptComponent;
class Entity {
public :

    virtual ~Entity();

    int getId() const{
        return id;
    }

    template <class T>
    T* getScript(){
        if(scripts.find(typeid(T).name()) != scripts.end()){
            return dynamic_cast<T*>(scripts[typeid(T).name()]);
        }
        return nullptr;
    }

    void addScript(ScriptComponent* script){
        std::string name = getComponentName(script);
        if(scripts.find(name) != scripts.end()){
            std::cerr<<"Components already exist"<<std::endl;
        }
        else{
            scripts[name] = script;
        }
    }

    template <class T>
    void removeScript(){
        if(scripts.find(typeid(T).name()) != scripts.end())
        {
            ScriptComponent* component = scripts[typeid(T).name()];
            delete component;
            scripts[typeid(T).name()] = nullptr;
        }
        else{
            std::cerr<<"Components don't exist !"<<std::endl;
        }
    }

    template <class T>
    T* getComponent(){
        if(components.find(typeid(T).name()) != components.end())
        {
            return dynamic_cast<T*>(components[typeid(T).name()]);
        }
        return nullptr;
    }

    void addComponent(Component* component) {
        std::string name = getComponentName(component);
        if(components.find(name) != components.end()){
            std::cerr<<"Components already exist"<<std::endl;
        }
        else{
            components[name] = component;
        }
    }

    template <class T>
    void removeComponent(){
        if(components.find(typeid(T).name()) != components.end())
        {
            Component* component = components[typeid(T).name()];
            delete component;
            components[typeid(T).name()] = nullptr;
        }
        else{
            std::cerr<<"Components don't exist !"<<std::endl;
        }
    }

    IController* getBoss(){
        return boss;
    }

    sf::Vector2u getSize(){
        return size;
    }

    std::string getLayer(){
        return layer;
    }

    std::string getComponentName(Component* component);

    std::string getComponentName(ScriptComponent* component);

    virtual void update(sf::Time){};

    static void OnCollision(Entity* entity, BoxColliderComponent * collider);

protected :
    static int nextId;
    Entity(IController* boss);

    sf::Vector2u size;
    IController* boss;
    std::string name;
    std::string layer;
    const int id;

    std::map<std::string, Component*> components;
    std::map<std::string, ScriptComponent*> scripts;
};

#endif //RPG_MVC_ENTITY_HPP
