//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#include <App/views/MainMenuView.hpp>
#include <App/models/GUIButton.hpp>
#include "MainMenuController.hpp"
#include "GUIButtonView.hpp"

MainMenuController::MainMenuController() {
    view = new MainMenuView();
   // GUIButton* button = new GUIButton(sf::Vector2f(150.f, 150.f) , sf::Vector2u(20, 50), "default.button", "START GAME !");
    view->addButton(new GuiButtonView(new GUIButton(sf::Vector2f(150.f, 150.f) , sf::Vector2u(20, 50), "default.button", "START GAME !")));
}


MainMenuController::~MainMenuController() {

}
