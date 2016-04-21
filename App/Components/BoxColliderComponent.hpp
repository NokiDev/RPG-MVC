//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#ifndef RPG_MVC_BOXCOLLIDERCOMPONENT_HPP
#define RPG_MVC_BOXCOLLIDERCOMPONENT_HPP


#include <SFML/Graphics/Rect.hpp>

#include "Component.hpp"

class TriggerCollision;

/**
 * @brief Component, which handle collisions stuff
 **/
class BoxColliderComponent : public Component {
public:
    /**
     * @brief default ctor
     * @param Entity* owner of the component
     * @param sf::Vector2u size of the boxCollider
     * @param bool indicates if the box is a trigger or not default set to false
     * @param sf::Vector2f offset default set to (0,0)
     **/
    BoxColliderComponent(Entity *owner, sf::Vector2u size, bool trigger = false,
                         sf::Vector2f offset = sf::Vector2f(0.0f, 0.0f));

    /**
     * @brief dtor
     **/
    ~BoxColliderComponent();

    /**
     * @brief update component each frame
     * @param sf::Time deltaTime default set to Zero
     **/
    virtual void update(sf::Time deltaTime = sf::Time::Zero);

    /**
     * @brief onCollision enter function called when two colliders box collides
     * @param BoxCollider * collider which collide with this
     **/
    void onCollision(BoxColliderComponent *collider);

    /**
     * @brief onCollision enter called when collide with window
     * @param sf::FloatRect winBox
     **/
    void onCollision(sf::FloatRect box);

    /**
     * @brief onTrigger enter function called when a trigger Collider enter in another BoxCollider
     * @param TriggerCollision * collision object
     **/
    void onTriggerEnter(TriggerCollision *collision);

    /**
     * @brief onTrigger stay function called when a trigger Collider stay in (mean it's already entered) another BoxCollider
     * @param TriggerCollision * collision object
     **/
    void onTriggerStay(TriggerCollision *collision);

    /**
     * @brief onTrigger exit function called when a trigger Collider exit box of another BoxCollider
     * @param TriggerCollision * collision object
     **/
    void onTriggerExit(TriggerCollision *collision);

    sf::FloatRect getNextBox() const;

    sf::FloatRect getBox() const;

    sf::Vector2u getSize() const;

    sf::Vector2f getOffset() const;

    bool isMoving() const;

    bool isTrigger() const;

private:
    sf::Vector2u size;
    bool trigger;
    bool moving;
    sf::Vector2f offset;
    sf::FloatRect box;
};


#endif //RPG_MVC_BOXCOLLIDERCOMPONENT_HPP
