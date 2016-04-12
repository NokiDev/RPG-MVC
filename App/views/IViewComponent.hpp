//
// Created by bluedragonfly on 3/22/16.
//

#ifndef RPG_MVC_IVIEWCOMPONENT_HPP
#define RPG_MVC_IVIEWCOMPONENT_HPP

#include <string>
#include "View.hpp"

class IViewComponent {

public:
    virtual void draw(View & view) = 0;
};


#endif //RPG_MVC_IVIEWCOMPONENT_HPP
