#ifndef PLAYER_H
#define PLAYER_H

#include "color.hpp"
#include "direction.h"
#include <string>
#include <list>

class Player
{
private:
  int _curBalls; //Number of balls on board.
  std::string _name;
  Color _color;

public:

  /**
   * @brief Constructor of player.
   * @param name Name of player.
   * @param color Color of player.
   */
  Player (std::string name, Color color);

  /**
  * @brief Get the amount of balls that the player has left in the game.
  * @return int number of balls.
  */
  int getCurBalls();

  /**
   * @brief Gets color of current player.
   * @return Color of the current player.
   */
  Color getColor();

  /**
   * @brief Reduces by one the number of curBalls;
   */
  void lostBall ();

};

#endif //_PLAYER_H
