#include "player.h"
#include "direction.h"
#include "position.hpp"
#include <string>
#include <list>


Player::Player (std::string name, Color color){
    _name = name;
    _curBalls = 14;
    _color = color;
}

int Player::getCurBalls()
{
    return _curBalls;
}

Color Player::getColor(){
    return _color;
}

void Player::lostBall(){
    _curBalls--;
}

