//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_INGAMECONTROLLER_HPP
#define RPG_MVC_INGAMECONTROLLER_HPP


#include <App/models/Player.hpp>
#include <App/Systems/EventSystem/EventsSystem.hpp>
#include <App/models/Enemy.hpp>
#include <App/Systems/PhysicsSystem/PhysicsSystem.hpp>
#include "IController.hpp"

class ScriptSystem;
class CollisionSystem;
class Map;
class IngameController : public IController {
public:

    IngameController();

    ~IngameController();

    virtual void handleEvents(sf::Event &event);

    virtual Entity* instantiate(Entity* entity, sf::Vector2f position, sf::Vector2i direction);
    virtual void destroy(Entity*entity);

    virtual void update(sf::Time deltaTime = sf::Time::Zero);

    virtual void render();

    virtual void setSubController(IController *newSubController);

    virtual void onClose();

    IController* getSubController();

    static int i;

private:
    IController *subController;
    Player* thePlayer;
    std::set<Entity*> entities;
    std::set<Entity*> entitiesToDestroy;
    CollisionSystem* collSys;
    EventsSystem* eventSys;
    ScriptSystem* scriptSys;
    PhysicsSystem* physicsSys;

    bool subControllerExist() const;

    bool viewExist() const;
};


#endif //RPG_MVC_INGAMECONTROLLER_HPP
