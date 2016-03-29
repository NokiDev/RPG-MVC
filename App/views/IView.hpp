//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_IVIEW_HPP
#define RPG_MVC_IVIEW_HPP


#include <SFML/Graphics.hpp>
#include "IViewComponent.hpp"
#include "WindowManager.hpp"

class IView {
public:
    virtual ~IView() { };
    /*
     * @brief init default components for the view and default behaviours
     *
     */
    virtual void handleEvent(){
        manager->handleEvent();
    }
    /*
     *
     *
     */
    void addViewComponent(IViewComponent* component){
        components.push_back(component);
    };
    /*
     * @brief draw the wiew on window
     * @params sf::RenderWindow, window to draw on
     */
    virtual void render() const = 0;
    /*
     *
     *
     */
    virtual void draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default) = 0;

protected:
    WindowManager * manager;
    std::vector<IViewComponent*> components;
};


#endif //RPG_MVC_IVIEW_HPP
