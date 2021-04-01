#ifndef BOARD_H
#define BOARD_H

#include "vector"
#include "hexagon.hpp"

/**
 * @brief The Board class reprents the Board on which the game will be taking place.
 */
class Board
{
private:
    Hexagon _gameBoard[9][9];

public:
    /**
     * @brief Default board constructor.
     */
    Board();

    /**
     * @brief getInitBoard Fills the board so that it corresponds to the game of Abalone.
     * A board limited to 61 Positions and 14 pieces on each side.
     */
    void getInitBoard();

    /**
     * @brief getHexagon Gets the desired Hexagon by its position.
     * @param x A given horizontal axis coordinate.
     * @param y A given vertical axis coordinate.
     * @return  The desired Hexagon, if there is any.
     */
    Hexagon getHexagon(int x, int y);

    /**
    * @brief Verifies if a neighbour of a specific position in a given Direction has the same Color.
    *
    * @param position A given Position.
    * @param direction A given direction to follow.
    * @return true if they are the same Color.
    * @return false if they are not of the same Color.
    */
    bool checkNeigbourSameColor(Position position, Direction direction);

    /**
    * @brief Returns the Board as a string that can then be used to Display it in the terminal.
    *
    * @return std::string The game board as a String.
    */
    std::string toString();

    /**
     * @brief Adds the proper decorations on the left side of the game board for it to be easier to understand for the player.
     * @param y the line to decorate.
     * @return a string to be added in the final presentation of the game board.
     */
    std::string addLeftDecorations(int y);

    /**
     * @brief Adds the proper decorations on the right side of the game board for it to be easier to understand for the player.
     * @param y the line to decorate.
     * @return a string to be added in the final presentation of the game board.
     */
    std::string addRightDecorations(int y);

    /**
     * @brief Checks if case is empty at a certain position.
     * @param p Position to check at.
     * @return true if position is emtpy.
     * @return false otherwise.
     */
    bool isEmpty (Position p);

    /**
     * @brief Gets color of a given Position from the game board if it exists.
     * @param p Position to get color from.
     * @return Color of the desired Position
     */
    Color getColor(Position p);

    /**
     * @brief Gets the opposite color of the current position.
     * @param p Position to get opposite color from.
     * @return The opposite color.
     */
    Color getOppositeColor(Position p);
};

#endif // BOARD_H
