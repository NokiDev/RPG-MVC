//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_IVIEW_HPP
#define RPG_MVC_IVIEW_HPP


#include <SFML/Graphics.hpp>

class IView {
public:
    virtual ~IView(){};
    virtual void render(sf::RenderWindow & window)const =0;

protected:
    //Buttons
};


#endif //RPG_MVC_IVIEW_HPP
