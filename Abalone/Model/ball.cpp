#include "ball.h"
#include "stdbool.h"
#include "iostream"
#include "game.hpp"

Ball::Ball(Position ballPos, Color color){
    _p=ballPos;
    _c=color;
    _onBoard = true;
    }

Ball::Ball (const Ball &playerBall){
    _p = playerBall._p;
    _c = playerBall._c;
    }

bool Ball::getOnBoardBall (){
    return _onBoard;
}

void Ball::setOnBoardBall(bool onBoard){
    _onBoard = onBoard;
}

Position Ball::getPositionBall() {
    return _p;
}

void Ball::setPosition(Position p){
    _p=p;
}

Color Ball::getColorBall(){
    return _c;
}

void Ball::setColorBall(Color c){
    _c = c;
}

void Ball::fall(){
    setOnBoardBall(false);
}
