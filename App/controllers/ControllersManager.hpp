//
// Created by Noki, Timothé Van Deputte on 22/02/2016.
//

#ifndef RPG_MVC_MAINCONTROLLER_HPP
#define RPG_MVC_MAINCONTROLLER_HPP

class App;

class WindowManager;

class IController;
/**
 * @brief Manager of all controllers determines which controller is active
 **/
class ControllersManager {
public:
    /**
     * @brief default ctor
     * @param App reference to app
     **/
    ControllersManager(App *app);
    /**
     * @brief dtor
     **/
    ~ControllersManager();
    /**
     * @brief run the manager;
     **/
    void run();

    virtual void setCurrentMainController(IController *newSubController);

    IController *getCurrentMainController();

private:

    App *app;
    WindowManager *windowManager;
    IController *currentMainController;
    IController *nextController;
};


#endif //RPG_MVC_MAINCONTROLLER_HPP
