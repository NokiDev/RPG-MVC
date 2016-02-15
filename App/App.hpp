//
// Created by Noki, Timothé Van Deputte on 12/02/2016.
//

#ifndef RPG_MVC_APP_HPP
#define RPG_MVC_APP_HPP


#include "IController.hpp"

class App {
public:
    App();

    ~App();

    void run();

    void setMainController(IController *newMainController);

private:
    IController *currentMainController;
    sf::RenderWindow window;
    sf::Event event;
    bool running;

    bool mainControllerExist() const;

    void handleEvents();


};


#endif //RPG_MVC_APP_HPP
