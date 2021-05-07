#ifndef DIRECTION_H
#define DIRECTION_H
#include "iostream"

/**
 * @brief The different directions the player can choose
 * to move his pawn in.
 */
enum directionChoice
{
    NORTHEAST=1,
    NORTHWEST,
    SOUTHEAST,
    SOUTHWEST,
    EAST,
    WEST,
    NONE
};

/**
 * @brief The Direction class represents the axies in which a pawn can move.
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
    Direction( directionChoice directionC);

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
     * @brief Getter for horizontal position.
     * @return Returns _deltaX.
     */
    int getDeltaX();

    /**
     * @brief Gets directions choice.
     * @return Returns direction choice.
     */
    directionChoice getDirection();

    /**
     * @brief setDirection Setter for the direction object by copying a direction given as a parameter.
     * @param direction a given direction to replicate.
     */
    void setDirection( Direction direction);

    /**
     * @brief Overload of osStream. For display purposes.
     * @param stream Input.
     * @return String of direction.
     */
    friend std::ostream &operator<<(std::ostream &stream, Direction &dir);
};

#endif // DIRECTION_H
