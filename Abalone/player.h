#ifndef PLAYER_H
#define PLAYER_H

#include "ball.h"
#include "direction.h"
#include <string>
#include <list>

using namespace std;
class Player
{

public:
  list<Ball> getBalls();

  int getCurBalls();

  /**
 * @param value
 */
  int setCurBalls(int value);

  /**
 * Pseudo constructeur pour player.
 * @param color
 * @param name
 */
  Player initPlayer(bool color, string name);

  /**
 * @param position
 * @param direction
 */
  Position move(Position position, Direction direction);

  /**
 * @param position
 */
  bool validatePos(Position position);

  /**
 * @param position
 * @param direction
 */
  bool validateMove(Position position, Direction direction);

private:
  list<Ball> balls;
  int curBalls;
  string name;
};

#endif //_PLAYER_H
