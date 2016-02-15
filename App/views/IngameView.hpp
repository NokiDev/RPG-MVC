//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_INGAMEVIEW_HPP
#define RPG_MVC_INGAMEVIEW_HPP


#include "IView.hpp"

class IngameView  : public IView{
public:
    IngameView();
    ~IngameView();

    virtual  void render(sf::RenderWindow & window) const;

};


#endif //RPG_MVC_INGAMEVIEW_HPP
