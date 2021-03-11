#ifndef BOARD_H
#define BOARD_H
#include "vector"
#include "hexagon.hpp"

class Board
{
private:
    std::vector<std::vector<Hexagon>> _gameBoard;
    Hexagon _gameBoard[9][9] ={
        (nullptr,nullptr,nullptr,nullptr,Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon()),
        (nullptr,nullptr,nullptr,Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon()),
        (nullptr,nullptr,Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon()),
        (nullptr,Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon()),
        (Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon()),
        (Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon()),
        (Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon()),
        (Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon()),
        (Hexagon(),Hexagon(),Hexagon(),Hexagon(),Hexagon())
        };

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
    std::vector<std::vector<Hexagon>> getHexagon();
};

#endif // BOARD_H
