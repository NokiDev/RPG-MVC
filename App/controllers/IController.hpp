//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_ICONTROLLER_HPP
#define RPG_MVC_ICONTROLLER_HPP


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class View;
class GUIButton;
/**
 * @brief Interface for all controllers
 * */
class IController {
public:

    virtual ~IController() { };

    virtual void askForEvents();

    virtual void askForRender();
    /*
     * @brief behaviour to adopt for all window events (key pressed, key released, window resized, window closed etc...)
     * @params sf::Event, the event to handle
     */
    virtual void handleEvents(sf::Event &event);

    /*
     * @brief update all components of the controllers
     * @params sf::Time, time between two frames or default zero
     */
    virtual void update(sf::Time deltaTime = sf::Time::Zero) = 0;

    /*
     * @brief render the view attached to the controller
     * @params sf::RenderWindow, window to render on
     */
    virtual void render() = 0;

    virtual void onClose() = 0;

    View * getView();

protected:
    View *view;
};


#endif //RPG_MVC_ICONTROLLER_HPP
