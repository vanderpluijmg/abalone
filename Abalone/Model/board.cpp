#include "board.h"
#include "hexagon.hpp"

Board::Board()
{
}
void Board::getInitBoard()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; i < 9; i++)
        {
            if ((i == 0 && (j == 4 || j == 5 || j == 6 || j == 7 || j == 8)) ||
                (i == 1 && (j == 3 || j == 4 || j == 5 || j == 6 || j == 7 || j == 8)) ||
                (i == 2 && (j == 4 || j == 5 || j == 6)))
            {
                _gameBoard[j][i] = Hexagon(WHITE, j, i);
            }
            else if ((i == 6 && (j == 2 || j == 3 || j == 4)) ||
                     (i == 7 && (j == 0 || j == 1 || j == 2 || j == 3 || j == 4 || j == 5)) ||
                     (i == 8 && (j == 0 || j == 1 || j == 2 || j == 3 || j == 4)))
            {
                _gameBoard[j][i] = Hexagon(BLACK, j, i);
            }
            else if (((i == 0 && (j == 0 || j == 1 || j == 2 || j == 3)) ||
                      (i == 1 && (j == 0 || j == 1 || j == 2)) ||
                      (i == 2 && (j == 0 || j == 1)) ||
                      (i == 3 && (j == 0))) ||
                     ((i == 5 && (j == 8)) ||
                      (i == 6 && (j == 7 || j == 8)) ||
                      (i == 7 && (j == 6 || j == 7 || j == 8)) ||
                      (i == 8 && (j == 5 || j == 6 || j == 7 || j == 8))))
            {
                _gameBoard[j][j] = Hexagon(OUTOFBOUND, j, i);
            }
            else
            {
                _gameBoard[j][i] = Hexagon(EMPTY, j, i);
            }
        }
    }
}

Hexagon Board::getHexagon(int x, int y)
{
    return _gameBoard[x][y];
}
bool Board::checkNeigbourSameColor(Position position, Direction direction)
{
    Color origin = _gameBoard[position.getCol()][position.getRow()].getMarbleColor();
    Color comparedTo = _gameBoard[position.getCol() + direction.getDeltaX()][position.getRow() + direction.getDeltaY()].getMarbleColor();
    return origin == comparedTo;
}

std::ostream &operator<<(std::ostream &stream,Board board){
for (int i = 0; i < 9; i++)
{
stream << lineToString(stream,board,i);
}

}

std::ostream lineToString(std::ostream &stream,Board board,int line){

}
