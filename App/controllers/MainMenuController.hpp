//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#ifndef RPG_MVC_MAINMENUCONTROLLER_HPP
#define RPG_MVC_MAINMENUCONTROLLER_HPP


#include "IController.hpp"

class GuiButtonView;

class MainMenuController : public IController {
public:
    MainMenuController();
    ~MainMenuController();
private:


    std::vector<GuiButtonView*> buttons;
};


#endif //RPG_MVC_MAINMENUCONTROLLER_HPP
