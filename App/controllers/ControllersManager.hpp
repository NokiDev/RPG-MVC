//
// Created by Noki, Timothé Van Deputte on 22/02/2016.
//

#ifndef RPG_MVC_MAINCONTROLLER_HPP
#define RPG_MVC_MAINCONTROLLER_HPP



#include "IController.hpp"

class App;
class WindowManager;
class ControllersManager{
public:
    ControllersManager(App* app);

    ~ControllersManager();

    void run();

    virtual void setCurrentMainController(IController *newSubController);

    IController* getCurrentMainController() const;

private:

    App* app;
    WindowManager * windowManager;
    IController *currentMainController;
};


#endif //RPG_MVC_MAINCONTROLLER_HPP
