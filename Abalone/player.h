#ifndef PLAYER_H
#define PLAYER_H

#include "ball.h"
#include "direction.h"
#include <string>
#include <list>


class Player
{
private:
  std::list<Ball> balls;
  int curBalls;
  std::string name;
public:
  std::list<Ball> getBalls();

  int getCurBalls();

  int setCurBalls(int value);

  Player initPlayer(bool color, std::string name);

  Position move(Position position, Direction direction);

  bool validatePos(Position position);

  bool validateMove(Position position, Direction direction);
};

#endif //_PLAYER_H
