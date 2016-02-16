//
// Created by Noki, Timothé Van Deputte on 16/02/2016.
//

#ifndef RPG_MVC_RENDERANIMATEDCOMPONENT_HPP
#define RPG_MVC_RENDERANIMATEDCOMPONENT_HPP


#include "RenderComponent.hpp"

class RenderAnimatedComponent : public RenderComponent{
public:
    RenderAnimatedComponent(Entity* owner, std::string animationFileName, unsigned int nbFrames, sf::IntRect textureRect, float stepTime, bool paused, bool looped);
    ~RenderAnimatedComponent();

    virtual void update(sf::Time deltaTime = sf::Time::Zero);
    virtual void draw(sf::RenderWindow & window);
    void nextFrame();
    void setFrame(int nb);
    void setStaticFrame();

private:
    //unsigned int currentAnimationTypeIndex;
    unsigned int currentFrame;

    bool typicalAnimation;

    sf::IntRect frameSize;
    float stepTime;
    /*std::vector<sf::IntRect> m_frames;
    std::vector<float> m_stepTimes;
    const sf::Texture* m_texture*/
    bool paused;
    bool looped;

   /* std::map<int ,std::vector<Animation*>>animationsList;
    Animation* currentAnimation;*/
};


#endif //RPG_MVC_RENDERANIMATEDCOMPONENT_HPP
