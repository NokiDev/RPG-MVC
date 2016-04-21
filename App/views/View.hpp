//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_VIEW_HPP
#define RPG_MVC_VIEW_HPP


#include <SFML/Graphics.hpp>
#include <set>


class IController;

class WindowManager;

class IController;

class IViewComponent;

class View {
public:
    /**
     * @brief static reference to the current view, the view displayed by the main controller
     **/
    static View *currentView;

    /**
     * @brief default ctor
     * @param controller which manage this view
     **/
    View(IController *controller);

    /**
     * @brief dtor
     **/
    virtual ~View() { };

    /**
     * @brief ask to the windowManager if there is events
     **/
    virtual void askForEvent();

    /**
     * @brief ask to the windowManager if the key (param) is Pressed or not
     * @param key to test
     **/
    virtual bool isKeyPressed(sf::Keyboard::Key key);

    /**
     * @brief sendEvent to the controller link to this view
     * @param sf::Event event to send
     **/
    virtual void sendEvent(sf::Event &event);

    /**
     * @brief add a new component to render
     * @param component to add
     **/
    void addViewComponent(IViewComponent *component);

    /**
     * @brief remove a view component from components array
     * @param component to Remove
     **/
    void delViewComponent(IViewComponent *component);

    /**
     * @brief draw the wiew on window
     * @params sf::RenderWindow, window to draw on
     **/
    virtual void render() = 0;

    /**
     * @brief draw on the view
     * @see sf::Window::draw
     **/
    virtual void draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default) = 0;

    sf::Vector2u getSize();

protected:
    WindowManager *manager;
    IController *controller;
    std::set<IViewComponent *> components;
};


#endif //RPG_MVC_VIEW_HPP
