//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#ifndef RPG_MVC_GUIBUTTONVIEW_HPP
#define RPG_MVC_GUIBUTTONVIEW_HPP


#include <App/models/GUIButton.hpp>
#include <SFML/Graphics.hpp>

class GuiButtonView {
public:
    GuiButtonView(GUIButton * button);
    ~GuiButtonView();
    void render(sf::RenderWindow & window);
private:
    sf::Sprite sprite;
    GUIButton *button;
};


#endif //RPG_MVC_GUIBUTTONVIEW_HPP
