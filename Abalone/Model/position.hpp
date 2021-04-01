#ifndef POSITION_H
#define POSITION_H
#include "direction.h"
#include "iostream"

class Position
{
private:
    int _x;
    int _y;

public:
    /**
     * @brief Position constructor
     * @param x value of position.
     * @param y value of position.
     */
    Position(int x = 0, int y = 0)
    {
        _x = x;
        _y = y;
    }

    /**
     * @brief Copy constructor of Position.
     * @param pos Position to copy.
     */
    Position( Position &pos)
    {
        _y = pos._y, _x = pos._x;
    }

    /**
     * @brief Creates a new posistion in the given direction
     * @param direction Direction to go in.
     * @return new position.
     */
    Position next(Direction direction)
    {
        Position p(getY() + direction.getDeltaX(), getX() + direction.getDeltaY());
        return p;
    }
    /**
     * @brief setter for position
     * @param target First position
     * @param source Last position
     */
    void static setPosition(Position &target, Position source){
            target._x=source._x;
            target._y=source._y;
        }

    void setPosition(Position target){
        _x = target._x;
        _y = target._y;
    }


    /**
     * @brief get's Row.
     * @return Row.
     */
    int getY()
    {
        return _y;
    }

    /**
     * @brief get's Column.
     * @return Col.
     */
    int getX()
    {
        return _x;
    }

    /**
     * @brief Overload of osStream. For display purposes.
     * @param stream Input.
     * @return String of position.
     */
    friend std::ostream &operator<<(std::ostream &stream, Position &pos)
    {
        return stream << "Position = " << std::to_string(pos.getX()) << ", " << std::to_string(pos.getY());
    }
    bool operator==(const Position & rhs) const {
       return (_x==rhs._x && _y==rhs._y);
    }

};
#endif // POSITION_H
