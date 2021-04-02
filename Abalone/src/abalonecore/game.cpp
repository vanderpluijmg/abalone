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
            if( validateLinearAndSameColor(a))
                return 1;
        }
        //in case of 2 pos but the same direction as pos2 is compared to pos1.
        else if(a.pos1.next(a.dir)==a.pos2)
        {
            if( validateLinearAndSameColor(a))
                return 1;
        }
        else if( Game::validateLateralAndSameColor(a))
            return 2;
    }
    return 0;
}

bool Game::validateLinearAndSameColor(const MoveUtils& a){

    Position posMove = a.pos1.next(a.dir);
    //if next pos is OUTOFBOUND ball will move but will fall
    if(_board.getColor(posMove)==OUTOFBOUND)return true;

    //else
    std::vector<Position> attackGroup (5,Position());
    std::vector<Position> defenseGroup (5,Position());
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

    //    Direction directionBetween;
    //    int deltaX = a.pos2.getX()-a.pos1.getX();
    //    int deltaY = a.pos2.getY()-a.pos1.getY();
    //    if((deltaX==-1||deltaX==1||deltaX==0)&&(deltaY==-1||deltaY==1||deltaY==0)){
    //        directionBetween.setDirection(Direction(a.pos2.getX()-a.pos1.getX(),a.pos2.getY()-a.pos1.getY()));
    //    }
    //    else if((deltaX==-2||deltaX==2||deltaX==0)&&(deltaY==-2||deltaY==2||deltaY==0)){
    //        directionBetween.setDirection(Direction((a.pos2.getX()-a.pos1.getX())/2,(a.pos2.getY()-a.pos1.getY())/2));
    //    }
    //    if(directionBetween.getDirection()!=NONE)
    //    {

    Position positionBetween = findPositionBetween(a);
    if(positionBetween==a.pos2)return true;
    if(positionBetween.next(findDirectionBetween(a))==a.pos2){
        if (allSameColor(a,positionBetween)){
            if (!(checkAllCaseEmtpy(a, positionBetween))){
                return true;
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

bool Game::applyMove(MoveUtils moves,Color player){
    //utilise validate Move et faudra faire les methodes des  moves par rapport au numero envoye
    int optionMove=validateMove(moves,player);
    switch (optionMove) {
    case 0 : return false;
    case 1: return applyMoveLinear(moves,player);
    case 2: return applyMoveLateral(moves,player) ;
    }
    return false;
}

void Game::loseBall(Color playerl){
    playerl==BLACK ? _piecesBlack--:_piecesWhite--;
}


Color Game::whoLost(){
    if(_piecesBlack<=7)return BLACK;
    else if(_piecesWhite<=7)return WHITE;
    else return EMPTY;
}

bool Game::applyMoveLinear(const MoveUtils& a,Color color){
    Position posMove = a.pos1.next(a.dir);
    //if next pos is OUTOFBOUND ball will move but will fall
    if(_board.getColor(posMove)==OUTOFBOUND){
        _board.getHexagon(a.pos1.getX(),a.pos1.getY()).setMarbleColor(EMPTY);
        loseBall(color);
        return true;
    }
    if(_board.getColor(posMove)==EMPTY){
        _board.getHexagon(a.pos1.getX(),a.pos1.getY()).setMarbleColor(EMPTY);
        _board.getHexagon(posMove.getX(),posMove.getY()).setMarbleColor(color);
        return true;
    }
    //else
    std::vector<Position> attackGroup (5,Position());
    std::vector<Position> defenseGroup (5,Position());
    int sizeAttackGroup = 1;
    int sizeDefendGroup = 0;
    Color friendColor = _board.getColor(color);
    Color enemyColor = _board.getOppositeColor(color);

    attackGroup[0].setPosition(a.pos1);
    while (friendColor == _board.getColor(posMove))
    {
        attackGroup[sizeAttackGroup].setPosition(posMove);
        posMove.setPosition(posMove.next(a.dir));
        sizeAttackGroup++;

        //if next pos is OUTOFBOUND balls will move but the one in the front will fall
        //In truth only the fisrt ball in the list will disappear
        if(_board.getColor(posMove)==OUTOFBOUND){
            _board.getHexagon(attackGroup[0].getX(),attackGroup[0].getY()).setEmpty();
            loseBall(color);

            return true;
        }

        // if too many balls of our color, the move is cancelled.
        if(sizeAttackGroup > 3) return false;
        //We continue if the next one is of the same  color
    }
    attackGroup.resize(sizeAttackGroup);
    Position posDefend = attackGroup[attackGroup.size()-1].next(a.dir);
    if(_board.getColor(posDefend)==EMPTY){
        _board.getHexagon(a.pos1.getX(),a.pos1.getY()).setMarbleColor(EMPTY);
        _board.getHexagon(posDefend.getX(),posDefend.getY()).setMarbleColor(color);
        return true;
    }
    else if(_board.getColor(posDefend)==OUTOFBOUND){
        _board.getHexagon(a.pos1.getX(),a.pos1.getY()).setMarbleColor(EMPTY);
        loseBall(color);
        return true;
    }

    while (_board.getColor(posDefend) == enemyColor)
    {
        defenseGroup[sizeDefendGroup].setPosition(posDefend);
        posDefend.setPosition(posDefend.next(a.dir));
        sizeDefendGroup++;
        // if too many balls of enemy color, the move is cancelled.
        if(sizeDefendGroup >= 3||sizeAttackGroup<=sizeDefendGroup) return false;
        //if next pos is OUTOFBOUND balls will move but the one in the front will fall
        if(_board.getColor(posDefend)==OUTOFBOUND){
            _board.getHexagon(attackGroup[0].getX(),attackGroup[0].getY()).setEmpty();
            _board.getHexagon(defenseGroup[0].getX(),defenseGroup[0].getY()).setMarbleColor(color);
            if(_board.isOnBoard(defenseGroup[sizeDefendGroup].next(a.dir))){
                _board.getHexagon(defenseGroup[sizeDefendGroup].next(a.dir).getX(),defenseGroup[sizeDefendGroup].next(a.dir).getY()).setMarbleColor(enemyColor);
            } else loseBall(enemyColor);

        }

    }
    return true;

}



bool Game::applyMoveLateral(const MoveUtils& a,Color color){
    Direction directionBetween =findDirectionBetween(a);
    Position positionBetween=findPositionBetween(a);

    if(directionBetween.getDirection()!=NONE){
        if(positionBetween == a.pos2){
            //suppression couleur
            _board.getHexagon(a.pos1.getX(),a.pos1.getY()).setMarbleColor(EMPTY);
            _board.getHexagon(a.pos2.getX(),a.pos2.getY()).setMarbleColor(EMPTY);
            //mise couleur nouvelle position
            if(_board.getHexagon(a.pos1.next(a.dir).getX(),a.pos1.next(a.dir).getY()).getMarbleColor()!=OUTOFBOUND){
                _board.getHexagon(a.pos1.next(a.dir).getX(),a.pos1.next(a.dir).getY()).setMarbleColor(color);}else loseBall(color);
            if(_board.getHexagon(a.pos2.next(a.dir).getX(),a.pos2.next(a.dir).getY()).getMarbleColor()!=OUTOFBOUND){
                _board.getHexagon(a.pos2.next(a.dir).getX(),a.pos2.next(a.dir).getY()).setMarbleColor(color);}else loseBall(color);
            return true;
        }else if(positionBetween.next(directionBetween) == a.pos2){
            //suppression couleur
            _board.getHexagon(a.pos1.getX(),a.pos1.getY()).setMarbleColor(EMPTY);
            _board.getHexagon(a.pos2.getX(),a.pos2.getY()).setMarbleColor(EMPTY);
            _board.getHexagon(positionBetween.getX(),positionBetween.getY()).setMarbleColor(EMPTY);
            //mise couleur nouvelle position
            if(_board.getHexagon(a.pos1.next(a.dir).getX(),a.pos1.next(a.dir).getY()).getMarbleColor()!=OUTOFBOUND){
                _board.getHexagon(a.pos1.next(a.dir).getX(),a.pos1.next(a.dir).getY()).setMarbleColor(color);}else loseBall(color);
            if(_board.getHexagon(a.pos2.next(a.dir).getX(),a.pos2.next(a.dir).getY()).getMarbleColor()!=OUTOFBOUND){
                _board.getHexagon(a.pos2.next(a.dir).getX(),a.pos2.next(a.dir).getY()).setMarbleColor(color);}else loseBall(color);
            if(_board.getHexagon(positionBetween.next(a.dir).getX(),positionBetween.next(a.dir).getY()).getMarbleColor()!=OUTOFBOUND){
                _board.getHexagon(positionBetween.next(a.dir).getX(),positionBetween.next(a.dir).getY()).setMarbleColor(color);}else loseBall(color);
            return true;
        }
    }
    return false;
}



Position Game::findPositionBetween(const MoveUtils& a){
    if(findDirectionBetween(a).getDirection()!=NONE)
        return a.pos1.next(findDirectionBetween(a));
    else return Position(0,0);
}

Direction Game::findDirectionBetween(const MoveUtils& a){
    Direction directionBetween;
    int deltaX = a.pos2.getX()-a.pos1.getX();
    int deltaY = a.pos2.getY()-a.pos1.getY();
    if((deltaX==-1||deltaX==1||deltaX==0)&&(deltaY==-1||deltaY==1||deltaY==0)){
        directionBetween.setDirection(Direction(deltaX,deltaY));
    }
    else if((deltaX==-2||deltaX==2||deltaX==0)&&(deltaY==-2||deltaY==2||deltaY==0)){
        directionBetween.setDirection(Direction(deltaX/2,(deltaY/2)));
    }
    return directionBetween.getDirection()!=NONE ? directionBetween : Direction(NONE);
}







