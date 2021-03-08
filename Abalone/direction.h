#ifndef DIRECTION_H
#define DIRECTION_H

/**
 * @brief The different directions the player can take
 * to move his balls.
 */
class Direction
{
private:
    int col, row;

public:
    enum values
    {
        northEast = (1, 1),
        northWest = (-1, 1),
        southEast = (1, -1),
        southWest = (-1, -1),
        east = (1, 0),
        west = (-1, 0)
    };
    int getY()
    {
        return row;
    }
    int getX()
    {
        return col;
    }
};

#endif // DIRECTION_H
