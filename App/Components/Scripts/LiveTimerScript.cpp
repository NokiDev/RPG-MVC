//
// Created by bluedragonfly on 4/16/16.
//

#include "LiveTimerScript.hpp"
#include "Entity.hpp"


LiveTimerScript::LiveTimerScript(Entity *owner, float timeToLive) : ScriptComponent(owner), timeToLive(timeToLive), timer(0.f) {

}

LiveTimerScript::~LiveTimerScript() {

}

void LiveTimerScript::update(sf::Time deltaTime) {
    timer+=deltaTime.asSeconds();
    if(timer >timeToLive){
        timer = 0.f;
        std::cout<<"DESTROY LASER"<<std::endl;

        controller->destroy(owner);
    }

}
