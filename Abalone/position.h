#ifndef POSITION_H
#define POSITION_H
#include "direction.h"
#include "iostream"

class Position
{
private:
    int col, row;

public:
    /**
     * @brief Position constructor
     * @param x value of position.
     * @param y value of position.
     */
    Position(int x = 0, int y = 0);

    /**
     * @brief Copy constructor of Position.
     * @param pos Position to copy.
     */
    Position(const Position &pos);

    /**
     * @brief Creates a new posistion in the given direction
     * @param direction Direction to go in.
     * @return new position.
     */
    Position next(Direction direction);

    /**
     * @brief get's Row.
     * @return Row.
     */
    int getRow();

    /**
     * @brief get's Column.
     * @return Col.
     */
    int getCol();

    /**
     * @brief Overload of osStream. For display purposes.
     * @param stream Input.
     * @return String of position.
     */
    friend std::ostream &operator<<(std::ostream &stream, Position &pos)
    {
        return stream << "Position = " << std::to_string(pos.getCol()) << ", " << std::to_string(pos.getRow());
    }
};
#endif // POSITION_H
