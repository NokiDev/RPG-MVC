//
// Created by Noki, Timothé Van Deputte on 23/02/2016.
//

#ifndef RPG_MVC_VIEWSMANAGER_HPP
#define RPG_MVC_VIEWSMANAGER_HPP


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "View.hpp"

class ControllersManager;
class WindowManager {

public:
    WindowManager(ControllersManager * manager);
    ~WindowManager();

    void createWindow(sf::VideoMode mode, std::string title,sf::Uint32 style = sf::Style::Default , sf::ContextSettings context = sf::ContextSettings());

    bool isKeyPressed(sf::Keyboard::Key key);

    void handleEvent(View & view);

    void display();

    void clear();

    void close();

    sf::RenderWindow & Window();

    sf::Vector2u getWindowSize();

    static WindowManager * get();

private:
    static WindowManager * windowManager;
    sf::RenderWindow window;

    ControllersManager* manager;

    sf::Event event;

};


#endif //RPG_MVC_VIEWSMANAGER_HPP
