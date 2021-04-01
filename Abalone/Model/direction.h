#ifndef DIRECTION_H
#define DIRECTION_H

/**
 * @brief The different directions the player can take
 * to move his balls.
 */
enum directionChoice {

        northEast=1,
        northWest,
        southEast,
        southWest,
        east,
        west
    };
/**
 * @brief The Direction class represents a
 * choice with its axis.
 */
class Direction{
   private:
    directionChoice _directionC;
    int _deltaX;
    int _deltaY;
public:

    /**
     * @brief Direction constructor with x and y params.
     * @param x param for direction.
     * @param y param for direction.
     */
    Direction (int x, int y);

    /**
     * @brief Default direction constructor.
     */
    Direction();

    /**
     * @brief Direction constructor with axies.
     * @param directionC Direction choice of user.
     */
    Direction(directionChoice directionC);

    /**
     * @brief Direction copy constructor.
     * @param direction Direction to copy.
     */
    Direction (const Direction &direction);
    /**
     * @brief getter for DeltaY.
     * @return Returns DeltaY.
     */
    int getDeltaY();

    /**
     * @brief getter for DeltaX
     * @return delta X.
     */
    int getDeltaX();

    /**
     * @brief Gets directions choice.
     * @return direction choice
     */
    directionChoice getDirection();
};



#endif // DIRECTION_H
