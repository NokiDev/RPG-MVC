//
// Created by Noki, Timothé Van Deputte on 20/04/2016.
//

#ifndef RPG_MVC_TRIGGERCOLLISION_HPP
#define RPG_MVC_TRIGGERCOLLISION_HPP

class BoxColliderComponent;

/**
 * @brief collision object for triggerColliders
 **/
class TriggerCollision {
public:
    /**
     * @brief default ctor
     * @param BoxColliderComponent * trigger collider component
     * @param BoxColliderComponent * collider component
     **/
    TriggerCollision(BoxColliderComponent *trigger, BoxColliderComponent *collider);

    /**
     * @brief dtor
     **/
    ~TriggerCollision();

    /*
     * @brief checkCollExistOrNot
     * @warning Not USED!
     **/
    bool collExist(BoxColliderComponent *trigger, BoxColliderComponent *collider);

    /*
     * @brief whether is collide or not
     * @warning Not USED!
     **/
    bool isCollide();

    BoxColliderComponent *getTrigger();

    BoxColliderComponent *getCollider();

private:
    BoxColliderComponent *trigger;
    BoxColliderComponent *collider;
};


#endif //RPG_MVC_TRIGGERCOLLISION_HPP
