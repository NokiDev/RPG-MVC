//
// Created by bluedragonfly on 3/22/16.
//

#ifndef RPG_MVC_IVIEWCOMPONENT_HPP
#define RPG_MVC_IVIEWCOMPONENT_HPP

#include <string>
#include "View.hpp"

/**
 * @brief main class for View Components
 **/
class IViewComponent {

public:
    /**
     * @brief dtor
     **/
    virtual ~IViewComponent() { };

    /**
     * @brief update the component each frame
     * @param sf::Time deltaTime, time between two frames
     **/
    virtual void update(sf::Time deltaTime) { };

    /**
     * @brief draw the component on the view
     * @param sf::View reference to the view to draw on
     * */
    virtual void draw(View &view) = 0;
};


#endif //RPG_MVC_IVIEWCOMPONENT_HPP
