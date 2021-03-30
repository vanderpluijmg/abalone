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
    Position(int x = 0, int y = 0)
    {
        col = x;
        row = y;
    }

    /**
     * @brief Copy constructor of Position.
     * @param pos Position to copy.
     */
    Position(const Position &pos)
    {
        row = pos.row, col = pos.col;
    }

    /**
     * @brief Creates a new posistion in the given direction
     * @param direction Direction to go in.
     * @return new position.
     */   
    Position next(Direction direction)
    {
        Position p(getRow() + direction.getDeltaX(), getCol() + direction.getDeltaY());
        return p;
    }
    /**
     * @brief setter for position
     * @param target First position
     * @param source Last position
     */
    void static setPosition(Position &target, Position source){
            target.col=source.col;
            target.row=source.row;
        }


    /**
     * @brief get's Row.
     * @return Row.
     */
    int getRow()
    {
        return row;
    }

    /**
     * @brief get's Column.
     * @return Col.
     */
    int getCol()
    {
        return col;
    }

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
