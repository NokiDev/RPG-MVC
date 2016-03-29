//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_INGAMEVIEW_HPP
#define RPG_MVC_INGAMEVIEW_HPP


#include <App/Systems/RenderSystem/RenderSystem.hpp>
#include "View.hpp"
#include "WindowManager.hpp"

class IngameView : public View {
public:
    IngameView(IController* controller);
    ~IngameView();
    virtual void render() const;
    virtual void draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default);
private:
    IController * controller;
};


#endif //RPG_MVC_INGAMEVIEW_HPP
