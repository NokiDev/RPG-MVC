//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#ifndef RPG_MVC_GUIBUTTON_HPP
#define RPG_MVC_GUIBUTTON_HPP


#include <SFML/System/Vector2.hpp>
#include <string>
#include <App/views/View.hpp>
#include <App/views/ViewTextComponent.hpp>

class GUIButton {
public:
    enum StateButton {DISABLED =-1, NORMAL , HOVER, SELECTED, CLICK};

    GUIButton(IController * boss, sf::Vector2f pos, sf::Vector2u size, std::string texture, std::string text, StateButton state = StateButton::NORMAL);
    GUIButton(IController* boss, sf::Vector2f pos,std::string text, StateButton state = StateButton::NORMAL);
    ~GUIButton();

    void update();

    void setPosition(sf::Vector2f pos);

    void setSize(sf::Vector2u size);

    void setText(std::string text);
    void setState(StateButton state);

    std::string getTexture();
    sf::Vector2f getPosition();
    sf::Vector2u getSize();
    std::string getText();
    StateButton getState();

private:

    IController * boss;

    sf::Vector2f position;
    sf::Vector2u size;
    std::string textStr;
    StateButton state;
    std::string texture;


    ViewComponent* viewRenderer;
    ViewTextComponent * textRenderer;
};


#endif //RPG_MVC_GUIBUTTON_HPP
