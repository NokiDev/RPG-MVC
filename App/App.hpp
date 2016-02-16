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
    /*
     * @brief Main loop of the application
     */
    void run();

    void setMainController(IController *newMainController);
    IController* getCurrentMainController() const;

    bool isRunning() const;
    bool isPaused() const;

private:
    IController *currentMainController;
    sf::RenderWindow window;
    sf::Event event;
    bool running;
    bool paused;

    sf::Clock time;
    sf::Time deltaTime;

    bool mainControllerExist() const;

    void handleEvents();


};


#endif //RPG_MVC_APP_HPP
