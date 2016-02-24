//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_IVIEW_HPP
#define RPG_MVC_IVIEW_HPP


#include <SFML/Graphics.hpp>
#include "GuiButtonView.hpp"

class IView {
public:
    virtual ~IView() { };
    /*
     * @brief draw the wiew on window
     * @params sf::RenderWindow, window to draw on
     */
    virtual void addButton(GuiButtonView* buttonView){
        buttons.push_back(buttonView);
    };
    virtual void render(sf::RenderWindow &window) const = 0;
    virtual void draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default) = 0;
protected:
    std::vector<GuiButtonView*> buttons;
    //Buttons
};


#endif //RPG_MVC_IVIEW_HPP
