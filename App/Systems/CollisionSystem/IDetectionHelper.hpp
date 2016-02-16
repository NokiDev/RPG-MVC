//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#ifndef RPG_MVC_IDETECTIONHELPER_HPP
#define RPG_MVC_IDETECTIONHELPER_HPP


#include <SFML/Graphics/Rect.hpp>

/**
 * @class IDetectionHelper
 * @brief Helper for detection
**/
class IDetectionHelper
{
public:
    /**
     * @brief Destructor
    **/
    virtual ~IDetectionHelper();
    /**
     * @brief Detect if the box is near to the other
     * @param dist maximum distance where the box is detect
     * @param box1 firstBox to test
     * @param box2 secondBox to test
    **/
    static bool DetectIsNear(int dist, sf::FloatRect box1, sf::FloatRect box2)
    {
        if (CalculateDistanceBetweenBoxes(box1, box2) <= dist)
        {
            return true;
        }
        return false;
    }
    /**
     * @brief Calculate distance between two boxes as Int
     * @param box1
     * @param box2
    **/
    static int CalculateDistanceBetweenBoxes(sf::FloatRect box1, sf::FloatRect box2)
    {
        sf::Vector2f vect1(box1.left + box1.width/2, box1.top + box1.height/2);
        sf::Vector2f vect2(box2.left + box2.width/2, box2.top + box2.height/2);

        float xDistance = vect1.x/32 - vect2.x/32;
        float yDistance = vect1.y/32 - vect2.y/32;
        if (xDistance <0)
            xDistance *= -1;
        if (yDistance <0)
            yDistance *= -1;

        int distance = xDistance + yDistance;

        return distance;
    }
    /**
     * @brief Calculate Vector distance between two boxes
     * @param box1
     * @param box2
    **/
    static sf::Vector2f CalculateVectorDistanceBetweenBoxes(sf::FloatRect box1, sf::FloatRect box2)
    {
        sf::Vector2f vect1(box1.left, box1.top);
        sf::Vector2f vect2(box2.left, box2.top);

        sf::Vector2f distance(float(vect1.x - vect2.x), float(vect1.y - vect2.y));
        return distance;
    }
    /**
     * @brief Calculate Absolute vector distance between two boxes
     * @param box1
     * @param box2
    **/
    static sf::Vector2f CalculateAbsDistanceBetweenBoxes(sf::FloatRect box1, sf::FloatRect box2)
    {
        sf::Vector2f vect1(box1.left, box1.top);
        sf::Vector2f vect2(box2.left, box2.top);

        sf::Vector2f distance(float(vect1.x - vect2.x), float(vect1.y - vect2.y));
        if(distance.y<0)
            distance.y *= -1;
        if(distance.x<0)
            distance.x *= -1;
        return distance;
    }
};


#endif //RPG_MVC_IDETECTIONHELPER_HPP
