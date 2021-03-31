#ifndef BOARD_H
#define BOARD_H

#include "vector"
#include "hexagon.hpp"

class Board
{
private:
    Hexagon _gameBoard[9][9] = {};

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
    friend std::ostream &operator<<(std::ostream &stream,Board board);

    /**
     * @brief Sends back the requested line of the _gameBoard as a string.
     *
     * @param line indicates which line it is.
     * @return std::string the outcome.
     */
    friend std::ostream lineToString(std::ostream &stream,Board board,int line);
};

#endif // BOARD_H
