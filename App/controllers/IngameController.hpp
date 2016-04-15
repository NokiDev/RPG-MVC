//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_INGAMECONTROLLER_HPP
#define RPG_MVC_INGAMECONTROLLER_HPP


#include <App/models/Player.hpp>
#include <App/Systems/EventSystem/EventsSystem.hpp>
#include "IController.hpp"

class CollisionSystem;
class Map;
class IngameController : public IController {
public:

    IngameController();

    ~IngameController();

    virtual void handleEvents(sf::Event &event);

    virtual Entity* instantiate(Entity* entity, sf::Vector2f position, sf::Vector2f direction);

    virtual void update(sf::Time deltaTime = sf::Time::Zero);

    virtual void render();

    virtual void setSubController(IController *newSubController);

    virtual void onClose();

    IController* getSubController();

private:
    IController *subController;
    Player* thePlayer;
    std::vector<Entity*> entities;
    Map * theMap;
    CollisionSystem* collSys;
    EventsSystem* eventSys;

    bool subControllerExist() const;

    bool viewExist() const;
};


#endif //RPG_MVC_INGAMECONTROLLER_HPP
