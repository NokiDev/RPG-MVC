//
// Created by Noki, Timothé Van Deputte on 23/02/2016.
//

#ifndef RPG_MVC_VIEWSMANAGER_HPP
#define RPG_MVC_VIEWSMANAGER_HPP


#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class ControllersManager;
class ViewsManager {

public:
    ViewsManager(ControllersManager * manager);
    ~ViewsManager();
    void createWindow(sf::VideoMode mode, std::string title,sf::Uint32 style = sf::Style::Default , sf::ContextSettings context = sf::ContextSettings());
    void run();

    void display();

    sf::RenderWindow & Window();

    void clean();

    void close();

private:
    sf::RenderWindow window;

    ControllersManager* manager;
    sf::Event event;
    void handleEvent();
};


#endif //RPG_MVC_VIEWSMANAGER_HPP
