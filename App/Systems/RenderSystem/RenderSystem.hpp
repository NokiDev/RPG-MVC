//
// Created by Noki, Timothé Van Deputte on 15/02/2016.
//

#ifndef RPG_MVC_RENDERSYSTEM_HPP
#define RPG_MVC_RENDERSYSTEM_HPP


#include <SFML/Graphics/RenderWindow.hpp>
#include <App/Components/RenderComponent.hpp>
#include <set>

class RenderSystem {
public:
    static RenderSystem* renderSystem;

    RenderSystem();
    ~RenderSystem();

    void addSprite(RenderComponent * sprite);
    void delSprite(RenderComponent * sprite);

    void draw(sf::RenderWindow & window);

    void update();

private:
    std::multiset<RenderComponent* , RenderComponent::depthCompare> renderComponents;


};


#endif //RPG_MVC_RENDERSYSTEM_HPP
