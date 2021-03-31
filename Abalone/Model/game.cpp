#include "game.h"

game::game(){

}

bool game::validateHorizontalAndSameColor(Position i, Position f){
    int deltaX;
    f.getY()>i.getY()? deltaX =2 : deltaX=-2;
    Position inBetween ((i.getX()),(f.getY()-(deltaX-1)));
    if (i.getX() == f.getX())
        if (((i.getY()+deltaX)==f.getY()))
            if (((i.getY()+1) ==(inBetween.getY())))
                    if ((inBetween.getY()) == (f.getY()-1))
                    //all three posisitions have same color
                    return true;
    return false;
}

bool game::validateMove(moveUtils a){
    if (a.pos2.getX()==-15 && a.pos2.getY()==-15){

    }
    else {
        if (game::validateHorizontalAndSameColor(a.pos1, a.pos2))
            return false;
    }
    return true;

}
