//
// Created by bluedragonfly on 4/17/16.
//

#ifndef RPG_MVC_ENNEMY_HPP
#define RPG_MVC_ENNEMY_HPP


#include "Entity.hpp"

class ViewSpriteComponent;
class Enemy : public Entity{

public :
    Enemy(IController* boss);
    ~Enemy();



private :
    ViewSpriteComponent * spriteRenderer;


};


#endif //RPG_MVC_ENNEMY_HPP
