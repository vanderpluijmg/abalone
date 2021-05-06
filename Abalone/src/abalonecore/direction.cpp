#include "direction.h"

Direction::Direction()
{

}

Direction::Direction (int deltaX, int deltaY)
{
    _deltaX=deltaX;
    _deltaY=deltaY;
    if (_deltaX==1&&_deltaY==-1)
        _directionC = NORTHEAST;

    else if (_deltaX==0&&_deltaY==1)
        _directionC = SOUTHEAST;

    else if (_deltaX==-1&&_deltaY==1)
        _directionC = SOUTHWEST;

    else if (_deltaX==-1&&_deltaY==0)
        _directionC = WEST;

    else if (_deltaX==0&&_deltaY==-1)
        _directionC = NORTHWEST;

    else if (_deltaX==1&&_deltaY==0)
        _directionC = EAST;

    else setDirection(NONE);
}

Direction::Direction( directionChoice directionC)
{
    switch (directionC) {
    case NORTHEAST:{ _directionC=directionC; _deltaX=1; _deltaY=-1; break;}
    case SOUTHEAST:{ _directionC=directionC; _deltaX=0; _deltaY=1; break;}
    case SOUTHWEST:{ _directionC=directionC; _deltaX=-1; _deltaY=1; break;}
    case WEST:{ _directionC=directionC; _deltaX=-1; _deltaY=0; break;}
    case NORTHWEST:{ _directionC=directionC; _deltaX=0; _deltaY=-1; break;}
    case EAST:{ _directionC=directionC; _deltaX=0; _deltaY=1; break;}
    case NONE:{ _directionC=directionC; _deltaX=0;_deltaY=0;break;}
    }
}

Direction::Direction (const Direction &direction)
{
    _deltaX = direction._deltaX;
    _deltaY = direction._deltaY;
    _directionC = direction._directionC;
}

int Direction::getDeltaY()
{
    return _deltaY;
}

int Direction::getDeltaX()
{
    return _deltaX;
}

directionChoice Direction::getDirection()
{
    return _directionC;
}

void Direction::setDirection( Direction direction)
{
    _deltaX=direction._deltaX;
    _deltaY=direction._deltaY;
}

std::ostream &operator<<(std::ostream &stream, Direction &dir)
{
    return stream << "Direction = " << std::to_string(dir.getDeltaX()) << ", " << std::to_string(dir.getDeltaY());
}
