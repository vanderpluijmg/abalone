#include "player.h"
#include "ball.h"
#include "direction.h"
#include <string>
#include <list>


Player::Player (std::string name, Color c){
    std::list<Ball> balls;
    initBalls(c);

}
std::list<Ball> Player::getBalls()
{
    return balls;
}

int Player::getCurBalls()
{
    return curBalls;
}

void Player::setCurBalls(int value)
{
    curBalls = value;
}


Player Player::initPlayer(bool color, std::string name)
{

}

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
    if (c==black){
        for (auto &x : balls){

        }
    }
    else {

}


