//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_IVIEW_HPP
#define RPG_MVC_IVIEW_HPP


#include <SFML/Graphics.hpp>
#include <App/controllers/IController.hpp>
#include "ViewComponent.hpp"

class WindowManager;
class IController;
class View {
public:

    View(IController * controller);

    virtual ~View() { };
    /*
     * @brief init default components for the view and default behaviours
     *
     */
    virtual void askForEvent();
    /*
     *
     *
     */
    virtual void sendEvent(sf::Event&event);
    /*
     *
     *
     */
    void addViewComponent(ViewComponent * component){
        components.push_back(component);
    };
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

protected:
    WindowManager * manager;
    IController * controller;
    std::vector<ViewComponent *> components;
};


#endif //RPG_MVC_IVIEW_HPP
