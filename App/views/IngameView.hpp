//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_INGAMEVIEW_HPP
#define RPG_MVC_INGAMEVIEW_HPP


#include <App/Components/Scripts/Damageable.hpp>
#include "View.hpp"
#include "WindowManager.hpp"

class IngameView : public View {
public:
    IngameView(IController* controller);
    ~IngameView();
    virtual void render();
    virtual void draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default);

    template <typename T> std::string toString(const T& t) {
        std::ostringstream os;
        os<<t;
        return os.str();
    }


private:
    IController * controller;
    Damageable * playerHealth;
    sf::Sprite background;
    ViewTextComponent * hp;
    ViewTextComponent * time;
};


#endif //RPG_MVC_INGAMEVIEW_HPP
