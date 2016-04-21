//
// Created by Noki, Timothé Van Deputte on 14/02/2016.
//

#ifndef RPG_MVC_ICONTROLLER_HPP
#define RPG_MVC_ICONTROLLER_HPP


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <App/views/IViewComponent.hpp>


class View;
class GUIButton;
class ViewSpriteComponent;
class ViewTextComponent;
class Entity;
/**
 * @brief main Class for controllers
 **/
class IController {
public:
    /**
     * @brief dtor
     **/
    virtual ~IController() { };
    /**
     * @brief Ask to the view link to the controller to ask event to the window
     **/
    virtual void askForEvents();

    virtual void askForRender();//Not Used
    /*
     * @brief behaviour to adopt for all window events (key pressed, key released, window resized, window closed etc...)
     * @params sf::Event, the event to handle
     */
    virtual void handleEvents(sf::Event &event);
    /**
     * @brief ask View if the key(param) is Pressed
     * @param sf::Keyboard::Key key to test
    **/
    virtual bool isKeyPressed(sf::Keyboard::Key key);

    /*
     * @brief update all components of the controllers
     * @params sf::Time, time between two frames or default zero
     */
    virtual void update(sf::Time deltaTime = sf::Time::Zero) = 0;

    /*
     * @brief render the view attached to the controller
     * @params sf::RenderWindow, window to render on
     */
    virtual void render() = 0;

    /**
     * @brief behaviour to adopt when the controller is closed
     **/
    virtual void onClose() = 0;

    /**
     * @brief add a new SpriteRenderer in the View
     * @param texturename of the Sprite
     **/
    virtual ViewSpriteComponent* newSpriteRenderer(std::string textureName);

    /**
     * @brief  delSprite Renderer in the view
     * @param sprite to remove
     **/
    virtual void delSpriteRenderer(IViewComponent * sprite);

    /**
     * @brief add a new TextRenderer in the View
     * @param text of the textRenderer
     **/
    virtual ViewTextComponent* newTextRenderer(std::string text);

    /**
     * @brief Instantiate a entity in the controller
     ***/
    virtual Entity* instantiate(Entity* entity, sf::Vector2f position, sf::Vector2i direction){};
    /**
     * @brief Destroy an entity
     **/
    virtual void destroy(Entity*entity){};


    View * getView();

protected:
    View *view;
};


#endif //RPG_MVC_ICONTROLLER_HPP
