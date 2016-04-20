//
// Created by Noki, Timothé Van Deputte on 20/04/2016.
//

#ifndef RPG_MVC_TRIGGERCOLLISION_HPP
#define RPG_MVC_TRIGGERCOLLISION_HPP

class BoxColliderComponent;
class TriggerCollision
{
public:
    TriggerCollision(BoxColliderComponent* trigger, BoxColliderComponent* collider);
    ~TriggerCollision();

    bool collExist(BoxColliderComponent* trigger, BoxColliderComponent* collider);
    bool isCollide();

    BoxColliderComponent* getTrigger();
    BoxColliderComponent* getCollider();

private:
    BoxColliderComponent* trigger;
    BoxColliderComponent* collider;
};


#endif //RPG_MVC_TRIGGERCOLLISION_HPP
