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

    static View* currentView;

    View(IController * controller);

    virtual ~View() { };
    /*
     * @brief init default components for the view and default behaviours
     *
     */
    virtual void askForEvent();

    virtual bool isKeyPressed(sf::Keyboard::Key key);
    /*
     *
     *
     */
    virtual void sendEvent(sf::Event&event);
    /*
     *
     *
     */
    void addViewComponent(IViewComponent * component);


    void delViewComponent(IViewComponent * component);
    /*
     * @brief draw the wiew on window
     * @params sf::RenderWindow, window to draw on
     */
    virtual void render()  = 0;
    /*
     *
     *
     */
    virtual void draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default) = 0;

    sf::Vector2u getSize();

protected:
    WindowManager * manager;
    IController * controller;
    std::set<IViewComponent *> components;
};


#endif //RPG_MVC_VIEW_HPP
