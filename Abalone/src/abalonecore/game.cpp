#include "game.h"

Game::Game(){
    _board.initGameBoard();
}

int Game::validateMove(const MoveUtils& a,Color player)
{
    if(_board.getColor(a.pos1)!=player)return false;
    if(a.pos1.getX()!=-1 && a.pos1.getY()!=-1){
        if (a.pos2.getX()==-1 && a.pos2.getY()==-1)
        {
            if( validateLineAndSameColor(a))
                return 1;
        }
        //in case of 2 pos but the same direction as pos2 is compared to pos1.
        else if(a.pos1.next(a.dir)==a.pos2)
        {
            if( validateLineAndSameColor(a))
                return 1;
        }
        else if( Game::validateLateralAndSameColor(a))
            return 2;
    }
    return 0;
}

bool Game::validateLineAndSameColor(const MoveUtils& a){

    Position posMove = a.pos1.next(a.dir);
    //if next pos is OUTOFBOUND ball will move but will fall
    if(_board.getColor(posMove)==OUTOFBOUND)return true;

    //else
    std::vector<Position> attackGroup = {Position(0,0),Position(0,0),Position(0,0),Position(0,0),Position(0,0)};
    std::vector<Position> defenseGroup = {Position(0,0),Position(0,0),Position(0,0),Position(0,0),Position(0,0)};
    int sizeAttackGroup = 1;
    int sizeDefendGroup = 0;
    Color friendColor = _board.getColor(a.pos1);
    Color enemyColor = _board.getOppositeColor(a.pos1);

    attackGroup[0].setPosition(a.pos1);
    while (friendColor == _board.getColor(posMove))
    {
        attackGroup[sizeAttackGroup].setPosition(posMove);
        posMove.setPosition(posMove.next(a.dir));
        //if next pos is OUTOFBOUND balls will move but the one in the front will fall
        if(_board.getColor(posMove)==OUTOFBOUND)return true;
        sizeAttackGroup++;
        // if too many balls of our color, the move is cancelled.
        if(sizeAttackGroup > 3) return false;
        //We continue if the next one is of the same  color
    }
    attackGroup.resize(sizeAttackGroup);
    Position posDefend = attackGroup[attackGroup.size()-1].next(a.dir);
    while (_board.getColor(posDefend) == enemyColor)
    {
        defenseGroup[sizeAttackGroup].setPosition(posDefend);
        posDefend.setPosition(posDefend.next(a.dir));
        sizeDefendGroup++;
        // if too many balls of enemy color, the move is cancelled.
        if(sizeDefendGroup > 3||sizeAttackGroup<=sizeDefendGroup) return false;
        //if next pos is OUTOFBOUND balls will move but the one in the front will fall
        if(_board.getColor(posDefend)==OUTOFBOUND)return true;
    }
    return true;
}

bool Game::validateLateralAndSameColor(const MoveUtils& a){

    //    int deltaX;
    //    a.pos2.getX()>a.pos1.getX()? deltaX =2 : deltaX=-2;
    //    Position inBetweenExp ((a.pos1.getX()+(deltaX-1)),(a.pos2.getY()));
    //    if (a.pos1.getY() == a.pos2.getY())
    //        if (((a.pos1.getX()+deltaX)==a.pos2.getX()))
    //            if (((a.pos1.getX()+1) ==(inBetweenExp.getX())))
    //                if ((inBetweenExp.getX()) == (a.pos2.getX()-1))
    //                    if (allSameColor(a,inBetweenExp))
    //                        if (!(checkAllCaseEmtpy(a, inBetweenExp)))
    //                            return true;
    //    return false;

    int deltaZ = a.pos2.getX()-a.pos1.getX();
    int deltaY = a.pos2.getX()-a.pos1.getX();
    if((deltaZ==-2||deltaZ==2||deltaZ==0)&&(deltaY==-2||deltaY==2||deltaY==0)){
        Direction directionBetween = Direction(deltaZ/2,deltaY/2);
        if(directionBetween.getDirection()!=NONE){
            Position positionBetween = a.pos1.next(directionBetween);
            if(positionBetween.next(a.dir)==a.pos2){
                if (allSameColor(a,positionBetween)){
                    if (!(checkAllCaseEmtpy(a, positionBetween))){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Game::checkAllCaseEmtpy(const MoveUtils& a, Position inBetween){
    return (_board.isEmpty(a.pos1.next(a.dir))
            && (_board.isEmpty(a.pos2.next(a.dir)))
            && (_board.isEmpty(inBetween.next(a.dir))));
}

bool Game::allSameColor(const MoveUtils& a, Position inBetween){
    return (((_board.getColor(a.pos1))
             == (_board.getColor(a.pos2)))
            == (_board.getColor(inBetween)));
}

Board Game::getBoard(){
    return _board;
}

void Game::applyMove(MoveUtils moves,Color player){
    //utilise validate Move et faudra faire les methodes des  moves par rapport au numero envoye
    moves.dir;
    player;
}

void Game::loseBall(Color playerl){
    if(playerl==BLACK) {
        _piecesBlack--;
    } else _piecesWhite--;
}


Color Game::whoLost(){
    if(_piecesBlack<=7)return BLACK;
    else if(_piecesWhite<=7)return WHITE;
    else return EMPTY;
}






