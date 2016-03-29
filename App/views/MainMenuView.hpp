//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#ifndef RPG_MVC_MAINMENUVIEW_HPP
#define RPG_MVC_MAINMENUVIEW_HPP


#include <App/controllers/MainMenuController.hpp>
#include "IView.hpp"

class MainMenuView : public IView{
public:
    MainMenuView();
    ~MainMenuView();
    virtual void render() const;
    virtual void draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default);
private:

    MainMenuController* controller;

};


#endif //RPG_MVC_MAINMENUVIEW_HPP
