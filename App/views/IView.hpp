//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_IVIEW_HPP
#define RPG_MVC_IVIEW_HPP


#include <SFML/Graphics.hpp>
#include "IViewComponent.hpp"

class IView {
public:
    virtual ~IView() { };

    /*
     * @brief init default components for the view and default behaviours
     *
     */
    virtual void initView() = 0;
    /*
     * @brief draw the wiew on window
     * @params sf::RenderWindow, window to draw on
     */
    void addComponent(IViewComponent* component){
        components.push_back(component);
    };

    virtual void render(sf::RenderWindow &window) const = 0;

    virtual void draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default) = 0;

protected:
    std::vector<IViewComponent*> components;
};


#endif //RPG_MVC_IVIEW_HPP
