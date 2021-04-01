#ifndef BOARD_H
#define BOARD_H

#include "vector"
#include "hexagon.hpp"

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
     * @brief Pseudo constructor for board.
     */
    void getInitBoard();

    /**
     * @brief Gets all the hexagons on the board.
     * @return Returns a vector of vector for 2 players.
     */
    Hexagon getHexagon(int x, int y);

    /**
    * @brief Verifies if a neighbour of a specific position in a given Direction has the same Color.
    *
    * @param position a given Position.
    * @param direction a given direction to follow.
    * @return true if they are the same Color.
    * @return false if they are not of the same Color.
    */
    bool checkNeigbourSameColor(Position position, Direction direction);

    /**
    * @brief Returns the Board as a string that can then be used to Display it in the terminal.
    *
    * @return std::string the board as a String.
    */
    std::string toString();

    /**
     * @brief addLeftDecorations
     * @param y
     * @return
     */
    std::string addLeftDecorations(int y);

    /**
     * @brief addRightDecorations
     * @param y
     * @return
     */
    std::string addRightDecorations(int y);

    /**
     * @brief Checks if case is empty at a certain position.
     * @param p Position to check at.
     * @return True if position is emtpy.
     */
    bool isEmpty (Position p);

    /**
     * @brief Gets color of position on board.
     * @param p Position to get color from.
     * @return Color of position
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
