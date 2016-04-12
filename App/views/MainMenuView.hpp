//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#ifndef RPG_MVC_MAINMENUVIEW_HPP
#define RPG_MVC_MAINMENUVIEW_HPP


#include <App/controllers/MainMenuController.hpp>
#include "View.hpp"

class MainMenuView : public View {
public:
    MainMenuView(IController* controller);
    ~MainMenuView();

    virtual void render() ;
    virtual void draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default);

private:

    IController* controller;

};


#endif //RPG_MVC_MAINMENUVIEW_HPP
