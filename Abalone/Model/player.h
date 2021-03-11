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

  Player (std::string name, Color c);

 /**
 * @brief Returns the list of balls that the player in the game.
 * 
 * @return std::list<Ball> 
 */
  std::list<Ball> getBalls();

  /**
 * @brief Get the amount of balls that the player has left in the game.
 * 
 * @return int number of balls.
 */
  int getCurBalls();
  /**
 * @brief Set the Cur Balls object
 * 
 * @param value 
 * @return int 
 */
  void setCurBalls(int value);
  /**
 * @brief Initialises a Player with the given parametres. 
 * 
 * @param color a desired color. Either white or black.
 * @param name the name of the Player.
 * @return Player the constructed object.
 */
  Player initPlayer(bool color, std::string name);
/**
 * @brief Moves a ball, if there is one, from a given position in a certain direction.
 * 
 * @param position a given position.
 * @param direction a given direction.
 * @return Position the end position of the ball.
 */
  Position move(Position position, Direction direction);
/**
 * @brief Validates if a given position is on the board.
 * 
 * @param position a given position to validate
 * @return true if the Postion objects has coordinates that are valid.
 * @return false if the Postion objects doesn't have coordinates that are valid.
 */
  bool validatePos(Position position);
/**
 * @brief Validates if a given move is valid. Depends on the number of balls that are being pushed .
 * 
 * @param position a given position. Should be the position of a Ball.
 * @param direction a given direction.
 * @return true if nothing is blocking
 * @return false if cannot move.
 */
  bool validateMove(Position position, Direction direction);

  void initPlayerBalls (Color c);
};

#endif //_PLAYER_H
