#include "board.h"

Board::Board()
{
}
void Board::getInitBoard()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; i < 9; i++)
        {
            if ((i == 0 && j == 4 || j == 5 || j == 6 || j == 7 || j == 8) ||
                (i == 1 && j == 3 || j == 4 || j == 5 || j == 6 || j == 7 || j == 8) ||
                (i == 2 && j == 4 || j == 5 || j == 6))
            {
                _gameBoard[i][j] = Hexagon(WHITE, i, j);
            }
            else if ((i == 6 && j == 2 || j == 3 || j == 4) ||
                     (i == 7 && j == 0 || j == 1 || j == 2 || j == 3 || j == 4 || j == 5) ||
                     (i == 8 && j == 0 || j == 1 || j == 2 || j == 3 || j == 4))
            {
                _gameBoard[i][j] = Hexagon(BLACK, i, j);
            }
            else if (((i == 0 && j == 0 || j == 1 || j == 2 || j == 3) ||
                      (i == 1 && j == 0 || j == 1 || j == 2) ||
                      (i == 2 && j == 0 || j == 1) ||
                      (i == 3 && j == 0)) ||
                     ((i == 5 && j == 8) ||
                      (i == 6 && j == 7 || j == 8) ||
                      (i == 7 && j == 6 || j == 7 || j == 8) ||
                      (i == 8 && j == 5 || j == 6 || j == 7 || j == 8)))
            {
                _gameBoard[i][j] = Hexagon(OUTOFBOUND, i, j);
            }
            else
            {
                _gameBoard[i][j] = Hexagon(EMPTY, i, j);
            }
        }
    }
}

Hexagon Board::getHexagon(int x, int y)
{
    return _gameBoard[x][y];
}
