#include "board.h"
#include "hexagon.hpp"

Board::Board()
{
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

std::string Board::toString()
{
    std::string result = "";
    result.append("         - - - - -\n");

    for (int y = 0; y < 9; y++)
    {
        result.append(addLeftDecorations(y));
        for (int x = 0; x < 9; x++)
        {
            switch (_gameBoard[y][x].getMarbleColor())
            {
            case OUTOFBOUND:
                break;
            case EMPTY:
            {
                result.append(".");
                break;
            }
            case WHITE:
            {
                result.append("O");
                break;
            }
            case BLACK:
            {
                result.append("X");
                break;
            }
            }
            try
            {
                if ((_gameBoard[y][x + 1].getMarbleColor() == EMPTY || _gameBoard[y][x + 1].getMarbleColor() == WHITE || _gameBoard[y][x + 1].getMarbleColor() == BLACK)
                 && (_gameBoard[y][x].getMarbleColor() == EMPTY || _gameBoard[y][x].getMarbleColor() == WHITE || _gameBoard[y][x].getMarbleColor() == BLACK) && x + 1 < 9)
                {
                    result.append(" ");
                }
            }
            catch (const std::exception &e)
            {
                 result.append("mm");
            }
        }
        result.append(addRightDecorations(y));
        result.append("\n");
    }
    result.append("         - - - - -\n");
    result.append("          1 2 3 4 5\n");
    return result;
}

std::string Board::addLeftDecorations(int y)
{
    std::string result = "";
    switch (y)
    {
    case 0:
    {
        result.append("     I--/");
        break;
    }
    case 1:
    {
        result.append("    H--/");
        break;
    }
    case 2:
    {
        result.append("   G--/");
        break;
    }
    case 3:
    {
        result.append("  F--/");
        break;
    }
    case 4:
    {
        result.append(" E--(");
        break;
    }
    case 5:
    {
        result.append("  D--\\");
        break;
    }
    case 6:
    {
        result.append("   C--\\");
        break;
    }
    case 7:
    {
        result.append("    B--\\");
        break;
    }
    case 8:
    {
        result.append("     A--\\");
        break;
    }

    default:
        break;
    }
    return result;
}
std::string Board::addRightDecorations(int y)
{
    std::string result = "";
    switch (y)
    {
    case 0:
    {
        result.append("\\");
        break;
    }
    case 1:
    {
        result.append("\\");
        break;
    }
    case 2:
    {
        result.append("\\");
        break;
    }
    case 3:
    {
        result.append("\\");
        break;
    }
    case 4:
    {
        result.append(")");
        break;
    }
    case 5:
    {
        result.append("/ 9");
        break;
    }
    case 6:
    {
        result.append("/ 8");
        break;
    }
    case 7:
    {
        result.append("/ 7");
        break;
    }
    case 8:
    {
        result.append("/ 6");
        break;
    }

    default:
        break;
    }
    return result;
}

//pas encore fini faut ajouterles décorations autours
