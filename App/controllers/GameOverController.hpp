//
// Created by bluedragonfly on 4/21/16.
//

#ifndef RPG_MVC_GAMEOVERCONTROLLER_HPP
#define RPG_MVC_GAMEOVERCONTROLLER_HPP

#include "IController.hpp"

class GameOverController : public IController {
public :
    GameOverController();

    ~GameOverController();

    virtual void handleEvents(sf::Event &event);

    virtual void update(sf::Time deltaTime = sf::Time::Zero);

    virtual void render();

    virtual void onClose();


private :

};


#endif //RPG_MVC_GAMEOVERCONTROLLER_HPP
