//
// Created by Noki, Timothé Van Deputte on 12/02/2016.
//

#ifndef RPG_MVC_APP_HPP
#define RPG_MVC_APP_HPP


#include <App/controllers/ControllersManager.hpp>
#include "IController.hpp"

/**
 * @brief Main class of the program, start controller Manager
 *
 **/
class App {
public:
    /**
     * @brief default ctor
     **/
    App();
    /**
     * @brief dtor
     **/
    ~App();
    /**
     * @brief Main loop of the application
     **/
    void run();

    bool isRunning() const;
    bool isPaused() const;

    void close();
    sf::Time &DeltaTime();

    /**
     * @brief static get of the static app reference
     **/
    static App* get();

    static ControllersManager* getManager();

private:
    /**
     * @var static reference to the app (singleton)
     **/
    static App* app;
    /**
     * @var manager of controllers
     */
    ControllersManager * manager;

    /**
     * @var isRunning
     **/
    bool running;
    /**
     * @var is paused
     **/
    bool paused;

    sf::Clock time;
    sf::Time deltaTime;


};


#endif //RPG_MVC_APP_HPP
