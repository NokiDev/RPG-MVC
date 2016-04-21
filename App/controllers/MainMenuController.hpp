//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#ifndef RPG_MVC_MAINMENUCONTROLLER_HPP
#define RPG_MVC_MAINMENUCONTROLLER_HPP


#include <App/models/GUIButton.hpp>
#include "IController.hpp"

class MainMenuController : public IController {
public:
    MainMenuController();

    ~MainMenuController();


    virtual void handleEvents(sf::Event &event);

    virtual void update(sf::Time deltaTime = sf::Time::Zero);

    virtual void render();

    virtual void setSubController(IController *newSubController);

    virtual void onClose();


    void fireButton();

    void goDown();

    void goUp();


private:


    std::vector<GUIButton *> buttons;
    std::vector<GUIButton *>::iterator selectedButton;
};


#endif //RPG_MVC_MAINMENUCONTROLLER_HPP
