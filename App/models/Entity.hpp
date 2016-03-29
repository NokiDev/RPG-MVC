//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_ENTITY_HPP
#define RPG_MVC_ENTITY_HPP

#include <SFML/System.hpp>
#include <map>
#include <typeinfo>
#include <iostream>

class Component;
class Entity {
public :

    virtual ~Entity() {};
    /**
     * @brief Update the entity each frame
     * @params time between two frames
    **/
    virtual void update(sf::Time deltaTime = sf::Time::Zero) = 0;
    /**
     * @brief Update Physics velocity and position
     */
    virtual void physicsUpdate() = 0;
    /**
     * @brief Behaviour to adopt when entering on collision
     */
    virtual void onCollision() = 0;

    sf::Vector2f& getPosition() {
        return position;
    }

    sf::Vector2f& getVelocity() {
        return velocity;
    }

    int getSpeed() const{
        return speed;
    }

    float getZ()const{
        return z;
    }

    int getId() const{
        return id;
    }

    template <class T>
    T* getComponent(){

        std::cout<< typeid(T).name()<<std::endl;
        if(components.find(typeid(T).name()) != components.end())
        {
            return dynamic_cast<T*>(components[typeid(T).name()]);
        }
        std::cout<<"Component not found"<<std::endl;
        return nullptr;
    }

    void addComponent(std::string type, Component* component) {
        if(components.find(type) != components.end()){
            std::cerr<<"Components already exist"<<std::endl;
        }
        else{
            components[type] = component;
        }
    }

    template <class T>
    void removeComponent(){
        if(components.find(typeid(T).name()) != components.end())
        {
            components[typeid(T).name()] = nullptr;
        }
        else{
            std::cerr<<"Components don't exist !"<<std::endl;
        }
    }

protected :
    Entity() : id(nextId++){};
    sf::Vector2f position;
    float z; ///Depth for render ===NOT USED===
    sf::Vector2f velocity;
    int speed;
    std::string name;
    const int id;
    static int nextId;

    std::map<std::string, Component*> components;


};

#endif //RPG_MVC_ENTITY_HPP
