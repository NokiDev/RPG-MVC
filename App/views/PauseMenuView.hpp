//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#ifndef RPG_MVC_PAUSEMENUVIEW_HPP
#define RPG_MVC_PAUSEMENUVIEW_HPP

#include "View.hpp"

class PauseMenuView : public View {
public:
    PauseMenuView(IController* controller);
    ~PauseMenuView();

    virtual void render() ;
    virtual void draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default);

private:

    sf::Sprite background;
    IController* controller;

};


#endif //RPG_MVC_PauseMeNUVIEW_HPP
