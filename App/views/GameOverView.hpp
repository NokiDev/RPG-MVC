//
// Created by bluedragonfly on 4/21/16.
//

#ifndef RPG_MVC_GAMEOVERVIEW_HPP
#define RPG_MVC_GAMEOVERVIEW_HPP

#include "View.hpp"

class IController;
class GameOverView : public View{
public:
    GameOverView(IController* controller);
    ~GameOverView();
    virtual void render();
    virtual void draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default);

private:
    sf::Image background;
    sf::Texture texture;
    sf::Sprite sprite;
};


#endif //RPG_MVC_GAMEOVERVIEW_HPP
