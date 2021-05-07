#include "game.h"

Game::Game(){
    _board.initGameBoard();
}
bool Game::applyMove(MoveUtils moves,Color player) {
    return validateMove(moves,player) ? true : false;
}

int Game::validateMove(const MoveUtils& a,Color player) {
    if((_board.getColor(a.pos1)!=player))
        return false;
    return a.pos2.getX()==-1 && a.pos2.getY()==-1?
                validateLinearAndSameColor(a) : validateLateralAndSameColor(a);
}

bool Game::validateLateralAndSameColor(const MoveUtils& a){
    int deltaX;
    Position inBetweenExp (0,-5);
    a.pos2.getX()>a.pos1.getX()? deltaX =2 : deltaX=-2;
    if ((a.pos1.getX()+1 != a.pos2.getX()) && (a.pos1.getX()-1 != a.pos2.getX())){
        inBetweenExp.setPosition((a.pos1.getX()+(deltaX-1)),(a.pos2.getY()));
        if (a.pos1.getY() == a.pos2.getY())
            if (((a.pos1.getX()+deltaX)==a.pos2.getX()))
                if (((a.pos1.getX()+1) ==(inBetweenExp.getX())))
                    if ((inBetweenExp.getX()) == (a.pos2.getX()-1))
                        if (allSameColor(a,inBetweenExp))
                            if ((checkAllCaseEmtpy(a, inBetweenExp))){
                                return applyLateralMove(a, _board.getColor(a.pos1), inBetweenExp);
                            }
    }
    else {
        if (a.pos1.getY() == a.pos2.getY())
            if (((a.pos1.getX()+1)==a.pos2.getX()))
                if (allSameColor(a,inBetweenExp))
                    if ((checkAllCaseEmtpy(a, inBetweenExp))){
                        return applyLateralMove(a, _board.getColor(a.pos1), inBetweenExp);
                    }
    }
    return false;
}

bool Game::applyLateralMove(const MoveUtils& a,Color color, Position inBetweenExp){
    if (!(inBetweenExp == Position(0,-5))){
        _board.getHexagon(inBetweenExp.next(a.dir)).setMarbleColor(color);
        _board.getHexagon(inBetweenExp).setMarbleColor(EMPTY);
    }
    _board.getHexagon(a.pos1.next(a.dir)).setMarbleColor(color);
    _board.getHexagon(a.pos2.next(a.dir)).setMarbleColor(color);
    _board.getHexagon(a.pos1).setMarbleColor(EMPTY);
    _board.getHexagon(a.pos2).setMarbleColor(EMPTY);
    return true;
}

bool Game::checkAllCaseEmtpy(const MoveUtils& a, Position inBetweenExp){
    return !(inBetweenExp == Position(0,-5))?
                (_board.isEmpty(a.pos1.next(a.dir)) && _board.isEmpty(a.pos2.next(a.dir)) && _board.isEmpty(inBetweenExp.next(a.dir))) :
                (_board.isEmpty(a.pos1.next(a.dir)) && _board.isEmpty(a.pos2.next(a.dir)));
}

bool Game::allSameColor(const MoveUtils& a, Position inBetween){
    return inBetween == Position(0,-5) ?
                (_board.getColor(a.pos1) == _board.getColor(a.pos2)) :
                ((_board.getColor(a.pos1) == _board.getColor(a.pos2))&&(_board.getColor(a.pos2) == _board.getColor(inBetween)));
}

Board Game::getBoard(){
    return _board;
}


void Game::loseBall(Color playerl){
    playerl==BLACK ? _piecesBlack--:_piecesWhite--;
}


Color Game::whoLost(){
    if(_piecesBlack > 7 && _piecesWhite > 7)
        return EMPTY;
    return _piecesBlack<=7 ? BLACK : WHITE;
}

std::vector<Position> Game::createAttackGroup(Position begin, Color playerColor, Direction d){
    int sizeGroup = 1;
    Position posMove = begin.next(d);
    std::vector<Position> attackGroup (5,Position());
    attackGroup[0].setPosition(begin);
    while (playerColor == _board.getColor(posMove))
    {
        attackGroup[sizeGroup].setPosition(posMove);
        posMove.setPosition(posMove.next(d));
        sizeGroup++;
        if(_board.getColor(posMove)==OUTOFBOUND){
            _board.getHexagon(attackGroup[0].getX(),attackGroup[0].getY()).setEmpty();
            loseBall(playerColor);
        }
    }
    attackGroup.resize(sizeGroup);
    return attackGroup;
}

bool Game::createDefendGroup(const MoveUtils& a,Position begin, Color defendColor, const std::vector<Position>& attackGroup){
    std::vector<Position> defendGroup (5,Position());
    int sizeGroup = 0;
    if(_board.getColor(begin)==EMPTY){
        _board.getHexagon(a.pos1).setMarbleColor(EMPTY);
        _board.getHexagon(begin).setMarbleColor(_board.getOppositeColor(defendColor));
        return true;
    }
    else if(_board.getColor(begin)==OUTOFBOUND){
        _board.getHexagon(a.pos1).setMarbleColor(EMPTY);
        return true;
    }
    while (_board.getColor(begin) == defendColor) {
        defendGroup[sizeGroup].setPosition(begin);
        sizeGroup++;
        if(_board.getColor(begin)==OUTOFBOUND){
            _board.getHexagon(attackGroup[0]).setEmpty();
            _board.getHexagon(defendGroup[0]).setMarbleColor(_board.getOppositeColor(defendColor));
        }
        begin = begin.next(a.dir);
    }
    defendGroup.resize(sizeGroup);
    if (attackGroup.size()>defendGroup.size())
        if (applyLinearMove(defendGroup, attackGroup, a.dir, _board.getOppositeColor(defendColor))==true)
            return true;
    return false;
}

bool Game::applyLinearMove(std::vector<Position> defenseGroup, std::vector<Position> attackGroup, Direction d, Color playerColor){
    switch (defenseGroup.size()) {
    case 1 : _board.getHexagon(defenseGroup[0]).setMarbleColor(_board.getOppositeColor(playerColor));
        _board.getHexagon(defenseGroup[0]).setMarbleColor(playerColor);
        _board.getHexagon(attackGroup[0]).setMarbleColor(EMPTY);
        if(_board.isOnBoard(defenseGroup[0].next(d)))
            _board.getHexagon(defenseGroup[0].next(d)).setMarbleColor(_board.getOppositeColor(playerColor));
        return true;
    case 2 :
        _board.getHexagon(defenseGroup[0]).setMarbleColor(playerColor);
        _board.getHexagon(attackGroup[0]).setMarbleColor(EMPTY);
        if(_board.isOnBoard(defenseGroup[1].next(d)))
            _board.getHexagon(defenseGroup[1].next(d)).setMarbleColor(_board.getOppositeColor(playerColor));
        return true;
    case 3: return false;
    }
    return true;
}

bool Game::validateLinearAndSameColor(const MoveUtils& a){
    Position posMove = a.pos1.next(a.dir);
    Color playerColor = _board.getColor(a.pos1);
    if(_board.getColor(posMove)==OUTOFBOUND){
        _board.getHexagon(a.pos1.getX(),a.pos1.getY()).setMarbleColor(EMPTY);
        loseBall(playerColor);
        return true;
    }
    if(_board.getColor(posMove)==EMPTY){
        _board.getHexagon(a.pos1.getX(),a.pos1.getY()).setMarbleColor(EMPTY);
        _board.getHexagon(posMove.getX(),posMove.getY()).setMarbleColor(playerColor);
        return true;
    }
    std::vector<Position> attackGroup = createAttackGroup(a.pos1, playerColor, a.dir);
    return createDefendGroup(a, attackGroup[attackGroup.size()-1].next(a.dir),
            _board.getOppositeColor(playerColor), attackGroup);
}

Position Game::findPositionBetween(const MoveUtils& a){
    int deltaX;
    a.pos2.getX()>a.pos1.getX()? deltaX =2 : deltaX=-2;
    return Position((a.pos1.getX()+(deltaX-1)),(a.pos2.getY()));
}







