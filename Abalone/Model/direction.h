#ifndef DIRECTION_H
#define DIRECTION_H

/**
 * @brief The different directions the player can take
 * to move his game pieces.
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
 * @brief The Direction class represents the axies in which the game pieces can move.
 */
class Direction{
   private:
    directionChoice _directionC;
    int _deltaX;
    int _deltaY;
public:

    /**
     * @brief Direction constructor with x and y parameters.
     * @param x Represents the horizontal axis.
     * @param y Represents vertical axis.
     */
    Direction (int x, int y);

    /**
     * @brief Default Direction constructor.
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
     * @brief Getter for vertical position.
     * @return Returns _deltaY.
     */
    int getDeltaY();

    /**
     * @brief Getter for horiszontal position.
     * @return Returns _deltaX.
     */
    int getDeltaX();

    /**
     * @brief Gets directions choice.
     * @return Returns direction choice.
     */
    directionChoice getDirection();
};



#endif // DIRECTION_H
