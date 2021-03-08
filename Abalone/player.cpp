#include "player.h"

#include "Player.h"

/**
 * Player implementation
 */


/**
 * @return List<Ball>
 */
list<Ball> Player::getBalls() {
    return balls;
}

/**
 * @return Integer
 */
int Player::getCurBalls() {
    return curBalls;
}

/**
 * @param value
 * @return Integer
 */
int Player::setCurBalls(int value) {
    curBalls=value;
    return curBalls;
}

/**
 * Pseudo constructeur pour player.
 * @param color
 * @param name
 * @return Player
 */
Player Player::initPlayer(bool color, string name) {
    Player a= Player();
    return a;
}

/**
 * @param position
 * @param direction
 * @return Position
 */
Position Player::move(Position position, Direction direction) {
    Position a ;
    return a;
}

/**
 * @param position
 * @return boolean
 */
bool Player::validatePos(Position position) {
    return false;
}

/**
 * @param position
 * @param direction
 * @return boolean
 */
bool Player::validateMove(Position position, Direction direction) {
    return false;
}
