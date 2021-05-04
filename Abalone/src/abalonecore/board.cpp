#include "board.h"

Board::Board()
{
}

void Board::initGameBoard()
{
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if ((y == 0 && (x == 4 || x == 5 || x == 6 || x == 7 || x == 8)) ||
                    (y == 1 && (x == 3 || x == 4 || x == 5 || x == 6 || x == 7 || x == 8)) ||
                    (y == 2 && (x == 4 || x == 5 || x == 6)))
            {
                _board[y][x] = Hexagon(WHITE, x, y);
            }
            else if ((y == 6 && (x == 2 || x == 3 || x == 4)) ||
                     (y == 7 && (x == 0 || x == 1 || x == 2 || x == 3 || x == 4 || x == 5)) ||
                     (y == 8 && (x == 0 || x == 1 || x == 2 || x == 3 || x == 4)))
            {
                _board[y][x] = Hexagon(BLACK, x, y);
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
                _board[y][x] = Hexagon(OUTOFBOUND, x, y);
            }
            else
            {
                _board[y][x] = Hexagon(EMPTY, x, y);
            }
        }
    }
}



Hexagon& Board::getHexagon(int x, int y)
{
    return _board[y][x];
}

Hexagon& Board::getHexagon(Position p){
    return _board[p.getY()][p.getX()];
}

bool Board::checkNeigbourSameColor(Position position, Direction direction)
{
    Color origin = _board[position.getY()][position.getX()].getMarbleColor();
    Color comparedTo = _board[position.getY() + direction.getDeltaY()][position.getX() + direction.getDeltaX()].getMarbleColor();
    return origin == comparedTo;
}

std::string Board::toString()
{
    std::string result = "";
    result.append("         Player 1\n");
    result.append("         - - - - -\n");

    for (int y = 0; y < 9; y++)
    {
        result.append(addLeftDecorations(y));
        for (int x = 0; x < 9; x++)
        {
            switch (getColor(Position(x,y)))
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
                if((isEmpty(Position(x+1,y))||getColor(Position(x+1,y))==WHITE||getColor(Position(x+1,y))==BLACK) && (isEmpty(Position(x,y))||getColor(Position(x,y))==WHITE||getColor(Position(x,y))==BLACK) && x + 1 < 9)
                {
                    if(y==8){result.append("_");}
                    else result.append(" ");
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
    result.append("          \\ \\ \\ \\ \\ 6\n");
    result.append("           1 2 3 4 5\n");
    result.append("         Player 2\n");
    return result;
}

std::string Board::addLeftDecorations(int y)
{
    std::string result = "";
    switch (y)
    {
    case 0: {result.append("     I--/"); break;}
    case 1: {result.append("    H--/"); break;}
    case 2: {result.append("   G--/"); break;}
    case 3: {result.append("  F--/"); break;}
    case 4: {result.append(" E--("); break;}
    case 5: {result.append("  D--\\"); break;}
    case 6: {result.append("   C--\\"); break;}
    case 7: {result.append("    B--\\"); break;}
    case 8: {result.append("     A--\\"); break;}
    default: break;
    }
    return result;
}

std::string Board::addRightDecorations(int y)
{
    std::string result = "";
    switch (y)
    {
    case 0: {result.append("\\"); break;}
    case 1: {result.append("\\"); break;}
    case 2: {result.append("\\"); break;}
    case 3: {result.append("\\"); break;}
    case 4: {result.append(")"); break;}
    case 5: {result.append("/\\"); break;}
    case 6: {result.append("/\\ 9"); break;}
    case 7: {result.append("/\\ 8"); break;}
    case 8: {result.append("/\\ 7"); break;}
    default: break;
    }
    return result;
}

bool Board::isEmpty(Position p)
{
    return getColor(Position(p.getX(),p.getY())) == EMPTY;
}

Color Board::getColor(Position p)
{
    if(isOnBoard(p))
    {
        return getHexagon(p.getX(),p.getY()).getMarbleColor();
    }
    else return OUTOFBOUND;
}

Color Board::getOppositeColor(Color c)
{
    switch (c) {
        case BLACK : return WHITE;
        case WHITE : return BLACK;
        case EMPTY : return EMPTY;
    case OUTOFBOUND : return OUTOFBOUND;
    }
    return OUTOFBOUND;
}

bool Board::isOnBoard(Position p)
{
    //Out of board
    if(p.getX()<0||p.getX()>8 || p.getY()<0||p.getY()>8) return false;
    //Out of game board
    else if(getHexagon(p.getX(),p.getY()).getMarbleColor()==OUTOFBOUND)return false;
    else return true;
}
