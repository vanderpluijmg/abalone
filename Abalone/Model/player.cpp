#include "player.h"
#include "direction.h"
#include "position.hpp"
#include <string>
#include <list>


Player::Player (std::string name, Color c){
    _name = name;
    _curBalls = 14;
}

std::list<Ball> Player::getBalls()
{
    return balls;
}

int Player::getCurBalls()
{
    return _curBalls;
}

void Player::setCurBalls(int value)
{
    _curBalls = value;
}

//bool Player::blackPositionGood(int i, int j){
//     return((i==4&&j==0) || (i==5&&j==0) || (i==6&&j==0) || (i==7&&j==0) || (i==8&&j==0)
//            || (i==3&&j==1) || (i==4&&j==1) || (i==5&&j==1) || (i==6&&j==1) || (i==7&&j==1) || (i==8&&j==1 )
//            || (i==4&&j==2)|| (i==5&&j==2)|| (i==6&&j==2))? true:false;

//}

//bool Player::whitePositionGood(int i, int j){
//    return((i==0&&j==8) || (i==1&&j==8) || (i==2&&j==8) || (i==3&&j==8) || (i==4&&j==8)
//           || (i==0&&j==7) || (i==1&&j==7) || (i==2&&j==7) || (i==3&&j==7) || (i==4&&j==7) || (i==5&&j==7 )
//           || (i==2&&j==6)|| (i==3&&j==6)|| (i==4&&j==6))? true:false;
//}

Position Player::move(Position position, Direction direction)
{
    Position a;
    return a;
    //If ball falls curball --, (take ball out of list. TBD)
}

bool Player::validatePos(Position position)
{
    return false;
}

bool Player::validateMove(Position position, Direction direction)
{
    return false;
}

void Player::initPlayerBalls (Color c){
    for (int i = 0; i <= 8; i++){
        for (int j = 0; j <= 8; j++){
            if (c==BLACK && blackPositionGood(i,j))
             balls.push_back(Ball(Position(i,j), c));
            else if (c==WHITE &&whitePositionGood(i,j))
                balls.push_back(Ball(Position(i,j), c));
        }
    }
}

