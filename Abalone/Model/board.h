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
};



#endif // BOARD_H
