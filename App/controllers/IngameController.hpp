//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_INGAMECONTROLLER_HPP
#define RPG_MVC_INGAMECONTROLLER_HPP


#include "IController.hpp"

class IngameController : public IController {
public:

    IngameController();

    ~IngameController();

    virtual void handleInputs(sf::Event &event);

    virtual void update(sf::Time deltaTime = sf::Time::Zero);

    virtual void render(sf::RenderWindow &window);

    virtual void setSubController(IController *newSubController);

    virtual void onClose();


private:
    IController *subController;

    bool subControllerExist() const;

    bool viewExist() const;
};


#endif //RPG_MVC_INGAMECONTROLLER_HPP
