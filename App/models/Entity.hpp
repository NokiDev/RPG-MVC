//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_ENTITY_HPP
#define RPG_MVC_ENTITY_HPP

#include <SFML/System.hpp>
#include <map>
#include <typeinfo>
#include <iostream>
#include <App/controllers/IController.hpp>

class BoxColliderComponent;
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
    virtual void onCollision(BoxColliderComponent * collider){};

    void setPosition(float x, float y){
        position.x = x;
        position.y = y;
    }

    void setPositionX(float x){
        setPosition(x, position.y);
    }

    void setPositionY(float y){
        setPosition(position.x, y);
    }

    void setPosition(sf::Vector2f pos){
        position= pos;
    }

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
        if(components.find(typeid(T).name()) != components.end())
        {
            return dynamic_cast<T*>(components[typeid(T).name()]);
        }
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

    void setVelocity(sf::Vector2<float> vel) {
        velocity = vel;
    }

    IController* getBoss(){
        return boss;
    }


    void setDirection(sf::Vector2f dir);

    sf::Vector2f getDirection();
protected :
    Entity() : id(nextId++){};
    IController* boss;
    sf::Vector2f position;
    sf::Vector2u size;
    float z; ///Depth for render ===NOT USED===
    sf::Vector2f velocity;
    sf::Vector2f direction;
    int speed;
    std::string name;
    const int id;

    static int nextId;


    std::map<std::string, Component*> components;
};

#endif //RPG_MVC_ENTITY_HPP
