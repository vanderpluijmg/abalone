#include "game.h"

game::game(){

}

bool game::validateInOneLine(Position i, Position f){
    if ((i.getCol() == (f.getCol()-2) || i.getCol() == (f.getCol()+2)) ||
            (i.getRow() == (f.getRow()-2) || i.getRow() == (f.getRow()+2)))
        return true;
    return false;
}

bool game::validateMove(moveUtils a){
    if (a.pos2.getCol()==-15 && a.pos2.getRow()==-15){

    }
    else {
        if (game::validateInOneLine(a.pos1, a.pos2))
            return false;
    }
    return true;

}
