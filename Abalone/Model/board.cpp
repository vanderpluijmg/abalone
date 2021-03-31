#include "board.h"
#include "hexagon.hpp"

Board::Board(){

}
void Board::getInitBoard()
{
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if ((y == 0 && (x == 4 || x == 5 || x == 6 || x == 7 || x == 8)) ||
                    (y == 1 && (x == 3 || x == 4 || x == 5 || x == 6 || x == 7 || x == 8)) ||
                    (y == 2 && (x == 4 || x == 5 || x == 6)))
            {
                _gameBoard[y][x] = Hexagon(WHITE, x, y);
            }
            else if ((y == 6 && (x == 2 || x == 3 || x == 4)) ||
                     (y == 7 && (x == 0 || x == 1 || x == 2 || x == 3 || x == 4 || x == 5)) ||
                     (y == 8 && (x == 0 || x == 1 || x == 2 || x == 3 || x == 4)))
            {
                _gameBoard[y][x] = Hexagon(BLACK, x, y);
            }
            else if (((y == 0 && (x == 0 || x == 1 || x == 2 || x == 3)) ||
                      (y == 1 && (x == 0 || x == 1 || x == 2)) ||
                      (y == 2 && (x == 0 || x == 1)) ||
                      (y == 3 && (x == 0))) ||
                     ((y == 5 && (x == 8)) ||
                      (y == 6 && (x == 7 || x == 8)) ||
                      (y == 7 && (x == 6 || x == 7 || x == 8)) ||
                      (y == 8 && (x == 5 || x == 6 || x == 7 || x == 8))))
            {
                _gameBoard[y][x] = Hexagon(OUTOFBOUND, x, y);
            }
            else
            {
                _gameBoard[y][x] = Hexagon(EMPTY, x, y);
            }
        }
    }
}

Hexagon Board::getHexagon(int x, int y)
{
    return _gameBoard[y][x];
}
bool Board::checkNeigbourSameColor(Position position, Direction direction)
{
    Color origin = _gameBoard[position.getY()][position.getX()].getMarbleColor();
    Color comparedTo = _gameBoard[position.getY() + direction.getDeltaY()][position.getX() + direction.getDeltaX()].getMarbleColor();
    return origin == comparedTo;
}

std::string Board::toString(){
    std::string result="";
    for (int y = 0; y < 9; y++){
        for (int x = 0; x < 9; x++)
        {
            switch (_gameBoard[y][x].getMarbleColor()){
            case OUTOFBOUND:break;
            case EMPTY:{
                result.append(".");
                break;
            }
            case WHITE:{
                result.append("o");
                break;
            }
            case BLACK:{
                result.append("x");
                break;
            }
            }
        }
        result.append("\n");
    }

    return result;
}
//pas encore fini faut ajouterles décorations autours



