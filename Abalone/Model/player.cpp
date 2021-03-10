#include "player.h"

/**
 * @return List<Ball>
 */
std::list<Ball> Player::getBalls()
{
    return balls;
}

int Player::getCurBalls()
{
    return curBalls;
}

int Player::setCurBalls(int value)
{
    curBalls = value;
    return curBalls;
}


Player Player::initPlayer(bool color, std::string name)
{
    Player a = Player();
    return a;
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

