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

class TriggerCollision;

class Component;

class ScriptComponent;
/**
 * @brief Base Class for all entites it's a container of components  and scripts
 **/
class Entity {
public :
    /**
     * @brief virtual dtor
     **/
    virtual ~Entity();

    int getId() const {
        return id;
    }


    /**
     * @brief getScript <Name> from the entity
     * @warning test if it's not nullptr
     * @important if not found return a nullptr
     **/
    template<class T>
    T *getScript() {
        if (scripts.find(typeid(T).name()) != scripts.end()) {
            return dynamic_cast<T *>(scripts[typeid(T).name()]);
        }
        return nullptr;
    }

    /**
     * @brief add a new Script to the entity
     * @warning if already exist the script is deleted so remove first;
     **/

    void addScript(ScriptComponent *script) {
        std::string name = getComponentName(script);
        if (scripts.find(name) != scripts.end()) {
            delete script;
            std::cerr << "Components already exist" << std::endl;
        }
        else {
            scripts[name] = script;
        }
    }

    /**
     * @brief removeScript<Name> from the entity if its present
     **/
    template<class T>
    void removeScript() {
        if (scripts.find(typeid(T).name()) != scripts.end()) {
            ScriptComponent *component = scripts[typeid(T).name()];
            delete component;
            scripts[typeid(T).name()] = nullptr;
        }
        else {
            std::cerr << "Components don't exist !" << std::endl;
        }
    }

    /**
     * @brief getComponent <Name> from the entity
     * @warning test if it's not nullptr
     * @important if not found return a nullptr
     **/
    template<class T>
    T *getComponent() {
        if (components.find(typeid(T).name()) != components.end()) {
            return dynamic_cast<T *>(components[typeid(T).name()]);
        }
        return nullptr;
    }

    /**
     * @brief add a new Component to the entity
     * @warning if already exist the component is deleted so remove first;
     **/
    void addComponent(Component *component) {
        std::string name = getComponentName(component);
        if (components.find(name) != components.end()) {
            std::cerr << "Component " << name << " already exist" << std::endl;
        }
        else {
            components[name] = component;
        }
    }

    /**
     * @brief removeScript<Name> from the entity if its present
     **/
    template<class T>
    void removeComponent() {
        if (components.find(typeid(T).name()) != components.end()) {
            Component *component = components[typeid(T).name()];
            delete component;
            components[typeid(T).name()] = nullptr;
        }
        else {
            std::cerr << "Component " << typeid(T).name() << " don't exist !" << std::endl;
        }
    }

    IController *getBoss() {
        return boss;
    }

    sf::Vector2u getSize() {
        return size;
    }

    std::string getLayer() {
        return layer;
    }

    std::string getName() {
        return name;
    }

    std::string getComponentName(Component *component);

    std::string getComponentName(ScriptComponent *component);


    /**
     * @brief update entity each frame
     * @param sf::Time deltaTime time between two frames
     **/
    virtual void update(sf::Time) { };

    /**
     * @brief call OnCollision for all script in the entity (param)
     **/
    static void OnCollision(Entity *entity, BoxColliderComponent *collider);
    /**
     * @brief call OnTriggerEnter for all script in the entity (param)
     **/
    static void OnTriggerEnter(Entity *entity, TriggerCollision *collider);
    /**
     * @brief call OnTriggerStay for all script in the entity (param)
     **/
    static void OnTriggerStay(Entity *entity, TriggerCollision *collider);
    /**
     * @brief call OnTriggerExit for all script in the entity (param)
     **/
    static void OnTriggerExit(Entity *entity, TriggerCollision *collider);

protected :
    static int nextId;

    Entity(IController *boss);

    sf::Vector2u size;
    IController *boss;
    std::string name;
    std::string layer;
    const int id;

    std::map<std::string, Component *> components;
    std::map<std::string, ScriptComponent *> scripts;
};

#endif //RPG_MVC_ENTITY_HPP
