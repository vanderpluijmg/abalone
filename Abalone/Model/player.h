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
  std::string _name;

public:

  /**
   * @brief Player constructor Player
   * @param name Name of player.
   * @param c Color of player.
   */
  Player (std::string name, Color c);

  /**
  * @brief Returns the list of balls that the player in the game.
  * @return std::list<Ball>
  */
  std::list<Ball> getBalls();

  /**
  * @brief Get the amount of balls that the player has left in the game.
  * @return int number of balls.
  */
  int getCurBalls();

  /**
  * @brief Sets the currents number of balls the player has on the board.
  * @param value Number of balls
  */
  void setCurBalls(int value);

  /**
  * @brief Moves a ball, if there is one, from a given position in a certain direction.
  * @param position a given position.
  * @param direction a given direction.
  * @return Position the end position of the ball.
  */
  Position move(Position position, Direction direction);

  /**
  * @brief Validates if a given position is on the board.
  * @param position a given position to validate
  * @return true if the Postion objects has coordinates that are valid.
  * @return false if the Postion objects doesn't have coordinates that are valid.
  */
  bool validatePos(Position position);
  /**
  * @brief Validates if a given move is valid. Depends on the number of balls that are being pushed .
  * @param position a given position. Should be the position of a Ball.
  * @param direction a given direction.
  * @return true if nothing is blocking
  * @return false if cannot move.
  */
  bool validateMove(Position position, Direction direction);

  /**
   * @brief Checks all black positions.
   * @param i x coordinate of position
   * @param j y coondinate of position.
   * @return True if is valid black position.
   */
  bool blackPositionGood(int i, int j);

  /**
   * @brief Checks all white positions.
   * @param i x coordinate of position
   * @param j y coondinate of position.
   * @return True if is valid white position.
   */
  bool whitePositionGood(int i, int j);

  /**
   * @brief Initializes the players starter balls.
   * @param c Color of balls.
   */
  void initPlayerBalls (Color c);


};

#endif //_PLAYER_H
