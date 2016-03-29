//
// Created by Noki, Timothé Van Deputte on 18/02/2016.
//

#include <App/views/MainMenuView.hpp>
#include <App/models/GUIButton.hpp>
#include "MainMenuController.hpp"

MainMenuController::MainMenuController() {
    view = new MainMenuView(this);
}


MainMenuController::~MainMenuController() {

}
