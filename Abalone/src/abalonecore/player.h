#ifndef PLAYER_H
#define PLAYER_H

#include "color.hpp"
#include "direction.h"
#include "position.hpp"
#include <string>
#include <list>

/**
 * @brief The Player class representing one of the two users using the program.
 */
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
   * @param color Color of game pieces that the player will be able to move.
   */
    Player (std::string name, Color color);

    /**
  * @brief Get the amount of game pieces that the player has left in the game.
  * @return int Number of game pieces.
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
