#include "game.h"

game::game(){

}

bool game::validateLateralAndSameColor(Position i, Position f){
    int deltaX;
    f.getX()>i.getX()? deltaX =2 : deltaX=-2;
    Position inBetween ((i.getX()+(deltaX-1)),(f.getY()));
    if (i.getY() == f.getY())
        if (((i.getX()+deltaX)==f.getX()))
            if (((i.getX()+1) ==(inBetween.getX())))
                if ((inBetween.getX()) == (f.getX()-1))
                    //Are all same color
                    return true;
    return false;
}
Position game::getInBetweenH(Position i, Position f){
    int deltaX;
    f.getX()>i.getX()? deltaX =2 : deltaX=-2;
    return Position ((i.getX()+(deltaX-1)),(f.getY()));
}

bool game::horizontalMoveCheckOne(moveUtils a){
    Direction dir;
    a.pos2.getX()-a.pos1.getX()>0? dir=directionChoice::east :
            dir=directionChoice::west;
    if (a.pos1.next(dir).getX()==a.pos2.getX() &&
            a.pos1.next(dir).getY()==a.pos2.getY()){//They are next to each other
        //a.pos1.next(a.dir) check if at this position its empty
        //a.pos2.next(a.dir) check if at this position its empty
        //if both empty ok
    } else {
        Position inBetween = getInBetweenH(a.pos1, a.pos2);
        //a.pos1.next(a.dir) check if at this position its empty
        //a.pos1.next(a.dir) check if at this position its empty
        //inBetween.next(a.dir) check if at this position its empty
        //if all 3 empty ok
    }
    return true;
}


bool game::validateMove(moveUtils a){
    if (a.pos2.getX()==-15 && a.pos2.getY()==-15){

    }
    else {
        if (game::validateLateralAndSameColor(a.pos1, a.pos2))
            return false;
    }
    return true;

}
