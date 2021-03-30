#include "board.h"

Board::Board()
{
}
void Board::getInitBoard()
{
    _gameBoard[0][0] = Hexagon(OUTOFBOUND, 0, 0);
    _gameBoard[0][1] = Hexagon(OUTOFBOUND, 0, 1);
    _gameBoard[0][2] = Hexagon(OUTOFBOUND, 0, 2);
    _gameBoard[0][3] = Hexagon(OUTOFBOUND, 0, 3);
    _gameBoard[0][4] = Hexagon(WHITE, 0, 4);
    _gameBoard[0][5] = Hexagon(WHITE, 0, 5);
    _gameBoard[0][6] = Hexagon(WHITE, 0, 6);
    _gameBoard[0][7] = Hexagon(WHITE, 0, 7);
    _gameBoard[0][8] = Hexagon(WHITE, 0, 8);
    _gameBoard[1][0] = Hexagon(OUTOFBOUND, 1, 0);
    _gameBoard[1][1] = Hexagon(OUTOFBOUND, 1, 1);
    _gameBoard[1][2] = Hexagon(OUTOFBOUND, 1, 2);
    _gameBoard[1][3] = Hexagon(WHITE, 1, 3);
    _gameBoard[1][4] = Hexagon(WHITE, 1, 4);
    _gameBoard[1][5] = Hexagon(WHITE, 1, 5);
    _gameBoard[1][6] = Hexagon(WHITE, 1, 6);
    _gameBoard[1][7] = Hexagon(WHITE, 1, 7);
    _gameBoard[1][8] = Hexagon(WHITE, 1, 8);
    _gameBoard[2][0] = Hexagon(OUTOFBOUND, 2, 0);
    _gameBoard[2][1] = Hexagon(OUTOFBOUND, 2, 1);
    _gameBoard[2][2] = Hexagon(EMPTY, 2, 2);
    _gameBoard[2][3] = Hexagon(EMPTY, 2, 3);
    _gameBoard[2][4] = Hexagon(WHITE, 2, 4);
    _gameBoard[2][5] = Hexagon(WHITE, 2, 5);
    _gameBoard[2][6] = Hexagon(WHITE, 2, 6);
    _gameBoard[2][7] = Hexagon(EMPTY, 2, 7);
    _gameBoard[2][8] = Hexagon(EMPTY, 2, 8);
    _gameBoard[3][0] = Hexagon(OUTOFBOUND, 3, 0);
    _gameBoard[3][1] = Hexagon(EMPTY, 3, 1);
    _gameBoard[3][2] = Hexagon(EMPTY, 3, 2);
    _gameBoard[3][3] = Hexagon(EMPTY, 3, 3);
    _gameBoard[3][4] = Hexagon(EMPTY, 3, 4);
    _gameBoard[3][5] = Hexagon(EMPTY, 3, 5);
    _gameBoard[3][6] = Hexagon(EMPTY, 3, 6);
    _gameBoard[3][7] = Hexagon(EMPTY, 3, 7);
    _gameBoard[3][8] = Hexagon(EMPTY, 3, 8);
    _gameBoard[4][0] = Hexagon(EMPTY, 4,0);
    _gameBoard[4][1] = Hexagon(EMPTY, 4,1);
    _gameBoard[4][2] = Hexagon(EMPTY, 4,2);
    _gameBoard[4][3] = Hexagon(EMPTY, 4,3);
    _gameBoard[4][4] = Hexagon(EMPTY, 4,4);
    _gameBoard[4][5] = Hexagon(EMPTY, 4,5);
    _gameBoard[4][6] = Hexagon(EMPTY, 4,6);
    _gameBoard[4][7] = Hexagon(EMPTY, 4,7);
    _gameBoard[4][8] = Hexagon(EMPTY, 4,8);
    _gameBoard[5][0] = Hexagon(EMPTY, 5,0);
    _gameBoard[5][1] = Hexagon(EMPTY, 5,1);
    _gameBoard[5][2] = Hexagon(EMPTY, 5,2);
    _gameBoard[5][3] = Hexagon(EMPTY, 5,3);
    _gameBoard[5][4] = Hexagon(EMPTY, 5,4);
    _gameBoard[5][5] = Hexagon(EMPTY, 5,5);
    _gameBoard[5][6] = Hexagon(EMPTY, 5,6);
    _gameBoard[5][7] = Hexagon(EMPTY, 5,7);
    _gameBoard[5][8] = Hexagon(OUTOFBOUND, 5,8);
    _gameBoard[6][0] = Hexagon(EMPTY, 6,0);
    _gameBoard[6][1] = Hexagon(EMPTY, 6,1);
    _gameBoard[6][2] = Hexagon(BLACK, 6,2);
    _gameBoard[6][3] = Hexagon(BLACK, 6,3);
    _gameBoard[6][4] = Hexagon(BLACK, 6,4);
    _gameBoard[6][5] = Hexagon(EMPTY, 6,5);
    _gameBoard[6][6] = Hexagon(EMPTY, 6,6);
    _gameBoard[6][7] = Hexagon(OUTOFBOUND, 6,7);
    _gameBoard[6][8] = Hexagon(OUTOFBOUND, 6,8);
    _gameBoard[7][0] = Hexagon(BLACK, 7,0);
    _gameBoard[7][1] = Hexagon(BLACK, 7,1);
    _gameBoard[7][2] = Hexagon(BLACK, 7,2);
    _gameBoard[7][3] = Hexagon(BLACK, 7,3);
    _gameBoard[7][4] = Hexagon(BLACK, 7,4);
    _gameBoard[7][5] = Hexagon(BLACK, 7,5);
    _gameBoard[7][6] = Hexagon(OUTOFBOUND, 7,6);
    _gameBoard[7][7] = Hexagon(OUTOFBOUND, 7,7);
    _gameBoard[7][8] = Hexagon(OUTOFBOUND, 7,8);
    _gameBoard[8][0] = Hexagon(BLACK, 8,0);
    _gameBoard[8][1] = Hexagon(BLACK, 8,1);
    _gameBoard[8][2] = Hexagon(BLACK, 8,2);
    _gameBoard[8][3] = Hexagon(BLACK, 8,3);
    _gameBoard[8][4] = Hexagon(BLACK, 8,4);
    _gameBoard[8][5] = Hexagon(OUTOFBOUND, 8,5);
    _gameBoard[8][6] = Hexagon(OUTOFBOUND, 8,6);
    _gameBoard[8][7] = Hexagon(OUTOFBOUND, 8,7);
    _gameBoard[8][8] = Hexagon(OUTOFBOUND, 8,8);
    
}

Hexagon Board::getHexagon(int x, int y)
{
    return _gameBoard[x][y];
}
