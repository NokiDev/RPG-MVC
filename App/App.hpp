//
// Created by Noki, Timothé Van Deputte on 12/02/2016.
//

#ifndef RPG_MVC_APP_HPP
#define RPG_MVC_APP_HPP


#include <App/controllers/ControllersManager.hpp>
#include "IController.hpp"

class App {
public:
    App();

    ~App();
    /*
     * @brief Main loop of the application
     */
    void run();

    bool isRunning() const;
    bool isPaused() const;
    sf::Time &DeltaTime();

private:

    ControllersManager * manager;

    bool running;
    bool paused;

    sf::Clock time;
    sf::Time deltaTime;


};


#endif //RPG_MVC_APP_HPP
