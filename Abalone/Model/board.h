#ifndef BOARD_H
#define BOARD_H
#include "vector"
#include "hexagon.hpp"

class Board
{
private:
    std::vector<std::vector<Hexagon>> gameBoard;
public:
    /**
     * @brief Default board constructor.
     */
    Board();

    /**
     * @brief Pseudo constructor for board.
     */
    void initBoard ();
    /**
     * @brief Gets all the hexagons on the board.
     * @return Returns a vector of vector for 2 players.
     */
    std::vector<std::vector<Hexagon>> getHexagon();
};

#endif // BOARD_H
