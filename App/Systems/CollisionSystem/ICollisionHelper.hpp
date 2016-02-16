//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#ifndef RPG_MVC_ICOLLISIONHELPER_HPP
#define RPG_MVC_ICOLLISIONHELPER_HPP

#include <App/Components/BoxColliderComponent.hpp>

/**
 * @struct Circle
 * @brief Helper for Circle collision
**/
struct Circle
{
    float x;
    float y;
    float rayon;
};

/**
 * @class ICollisionHelper
 * @brief Helper for collision gives a lot of functions for handle collisions
**/
class ICollisionHelper
{
public:
    /**
     * @enum NOT USED
    **/
    enum CollisionBorder{NONE, TOPBORDER, BOTBORDER, LEFTBORDER, RIGHTBORDER};
    /**
     * @brief Destructor
    **/
    virtual ~ICollisionHelper();
    /**
     * @brief Test Collision between two AABB
     * @param box1 first box to test
     * @param box2 second box to test
    **/
    static bool AABBCollision(sf::FloatRect box1, sf::FloatRect box2)
    {
        if((box2.left >= box1.left + box1.width)      // trop � droite
           || (box2.left + box2.width <= box1.left) // trop � gauche
           || (box2.top >= box1.top + box1.height) // trop en bas
           || (box2.top + box2.height <= box1.top))  // trop en haut
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    /**
     * @brief NOT USED
    **/
    static CollisionBorder GetColliderBorder(BoxColliderComponent & collBox1, BoxColliderComponent & collBox2)
    {
        sf::FloatRect box1 = collBox1.getNextBox();
        sf::FloatRect box2 = collBox2.getNextBox();
        if((box2.left < box1.left + box1.width) && (box2.left > box1.left))
        {
            return CollisionBorder::RIGHTBORDER;
        }
        if((box2.left + box2.width > box1.left) && (box2.left + box2.width < box1.left + box1.width) && (box2.top ))
        {
            return CollisionBorder::LEFTBORDER;
        }
        if(box2.top < box1.top + box1.height)
        {
            return CollisionBorder::BOTBORDER;
        }
        if(box2.top + box2.height > box1.top)
        {
            return CollisionBorder::TOPBORDER;
        }
    }
    /**
     * @brief Test if a AABB go out another AABB
     * @param velocity help to find movement direction
     * @param collBox1 box to test
     * @param collBox2 box to test
    **/
    static bool NotAABBCollision(sf::Vector2f velocity, sf::FloatRect box1, sf::FloatRect box2)
    {
        if(velocity.x > 0)//Up Movement
        {
            if(box2.left+box2.width > box1.left + box1.width)
                return true;
        }
        else if(velocity.x < 0) //Down movement
        {
            if(box2.left < box1.left || box2.top < box1.top)
                return true;
        }
        if(velocity.y > 0)// Right Movement
        {
            if(box2.top + box2.height > box1.top + box1.height)
                return true;
        }
        else if(velocity.y < 0) //Left Movement
        {
            if(box2.top < box1.top)
                return true;
        }
        return false;
    }
    /**
     * @brief Test if a point is inside a circle
     * @param C
     * @param x xCoord of the point
     * @param y yCoord of the point
    **/
    static bool PointInCircleCollision(Circle& C, float x, float y)
    {
        float d = (x-C.x)*(x-C.x) + (y-C.y)*(y-C.y);
        if(d <= (C.rayon*C.rayon))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif //RPG_MVC_ICOLLISIONHELPER_HPP
