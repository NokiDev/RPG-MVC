//
// Created by Noki, Timothé Van Deputte on 16/02/2016.
//

#include "RenderAnimatedComponent.hpp"


RenderAnimatedComponent::RenderAnimatedComponent(Entity *owner, std::string animationFileName, unsigned int nbFrames, sf::IntRect textureRect, float stepTime, bool paused, bool looped) : RenderComponent(owner, animationFileName) {
    sprite.setTextureRect(textureRect);
    frameSize = textureRect;
    this->stepTime = stepTime;
    this->currentFrame = 0;
    this->looped = looped;
    this->paused = paused;
}

RenderAnimatedComponent::~RenderAnimatedComponent() {

}


void RenderAnimatedComponent::update(sf::Time deltaTime) {


}

void RenderAnimatedComponent::draw(sf::RenderWindow &window) {
    RenderComponent::draw(window);
}

void RenderAnimatedComponent::nextFrame() {

}

void RenderAnimatedComponent::setFrame(int nb) {

}

void RenderAnimatedComponent::setStaticFrame() {

}


