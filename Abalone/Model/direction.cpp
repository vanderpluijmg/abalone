#include "direction.h"

Direction::Direction(){

}
Direction::Direction (int deltaX, int deltaY){
    _deltaX=deltaX;
    _deltaY=deltaY;
    if (_deltaX==1&&_deltaY==-1)
        _directionC = northEast;
    else if (_deltaX==0&&_deltaY==1)
        _directionC = southEast;
    else if (_deltaX==-1&&_deltaY==1)
        _directionC = southWest;
    else if (_deltaX==-1&&_deltaY==0)
        _directionC = west;
    else if (_deltaX==-0&&_deltaY==-1)
        _directionC = northWest;
    else _directionC = east;
}
Direction::Direction(directionChoice directionC){
    switch (directionC) {
    case northEast: _directionC=directionC; _deltaX=1; _deltaY=-1; break;
    case southEast: _directionC=directionC; _deltaX=0; _deltaY=1; break;
    case southWest: _directionC=directionC; _deltaX=-1; _deltaY=1; break;
    case west: _directionC=directionC; _deltaX=-1; _deltaY=0; break;
    case northWest: _directionC=directionC; _deltaX=0; _deltaY=-1; break;
    case east: _directionC=directionC; _deltaX=1; _deltaY=0; break;
    }
}

Direction::Direction (const Direction &direction){
    _deltaX = direction._deltaX;
    _deltaY = direction._deltaY;
    _directionC = direction._directionC;
}


int Direction::getDeltaY(){
    return _deltaY;
}

int Direction::getDeltaX(){
    return _deltaX;
}

directionChoice Direction::getDirection(){
    return _directionC;
}
