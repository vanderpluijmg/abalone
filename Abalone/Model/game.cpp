#include "game.h"

game::game(){
    _board.getInitBoard();
    std::cout<<_board.toString();
}

bool game::validateMove(moveUtils a){
    if (a.pos2.getX()==-15 && a.pos2.getY()==-15){
        if(validateLineAndSameColor(a))
            return true;
    } else if (game::validateLateralAndSameColor(a))
            return true;
    return false;
}


bool game::validateLineAndSameColor(moveUtils a){
    std::vector<Position> groupToMove (5);
    std::vector<Position> groupToDefend (5);
    int sizeGroupMove = 0;
    int sizeGroupDefend = 0;
    Position posMove = a.pos1;
    while (_board.getColor(posMove) == (_board.getColor(a.pos1))) {
        groupToMove[sizeGroupMove].setPosition(a.pos1);
        posMove = posMove.next(a.dir);
        sizeGroupMove++;
    }
    if (sizeGroupMove>=3){
        throw "Error";
    }
    Position posDefend = groupToMove[sizeGroupMove];
    while (_board.getColor(posDefend) == (_board.getOppositeColor(a.pos1))) {
        groupToDefend[sizeGroupMove].setPosition(posDefend);
        posDefend = posDefend.next(a.dir);
        sizeGroupDefend++;
    }
    if (sizeGroupDefend >= sizeGroupMove)
        return false;
    return true;
}

bool game::validateLateralAndSameColor(moveUtils a){
    int deltaX;
    a.pos2.getX()>a.pos1.getX()? deltaX =2 : deltaX=-2;
    Position inBetweenExp ((a.pos1.getX()+(deltaX-1)),(a.pos2.getY()));
    if (a.pos1.getY() == a.pos2.getY())
        if (((a.pos1.getX()+deltaX)==a.pos2.getX()))
            if (((a.pos1.getX()+1) ==(inBetweenExp.getX())))
                if ((inBetweenExp.getX()) == (a.pos2.getX()-1))
                    if (allSameColor(a,inBetweenExp))
                        if (horizontalMoveCheckOne(a, inBetweenExp))
                            return true;
    return false;
}

bool game::horizontalMoveCheckOne(moveUtils a, Position inBetween){
    return (_board.isEmpty(a.pos1.next(a.dir))
            && (_board.isEmpty(a.pos2.next(a.dir)))
            && (_board.isEmpty(inBetween.next(a.dir))));
}
bool game::allSameColor(moveUtils a, Position inBetween){
    return (((_board.getColor(a.pos1))
            == (_board.getColor(a.pos2)))
            == (_board.getColor(inBetween)));
}

bool game::allSameColor(std::vector<Position> p){
    Color color = _board.getColor(p[0]);
    for (auto& x : p){
        if (!(_board.getColor(x) == color))
            return false;
    }
    return true;
}



