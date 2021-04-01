#ifndef POSITION_H
#define POSITION_H
#include "direction.h"
#include "iostream"
/**
 * @brief The Position class represents the location of all the game board cells.
 */
class Position
{
private:
    int _x;
    int _y;

public:
    /**
     * @brief Position constructor
     * @param x Position on the horizontal axis.
     * @param y Position on vertical axis.
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
    Position(const Position &pos)
    {
        _y = pos._y;
        _x = pos._x;
    }

    /**
     * @brief Creates a new posistion in the given direction
     * @param direction Direction to go in.
     * @return new position.
     */
    Position next(Direction direction) const
    {
        Position p(getY() + direction.getDeltaX(), getX() + direction.getDeltaY());
        return p;
    }
    /**
     * @brief Setter for position
     * @param target Position to modify.
     * @param source Position to reproduce.
     */
    void static setPosition(Position &target, Position source){
        target._x=source._x;
        target._y=source._y;
    }

    /**
     * @brief setPosition sets the current position to the same as the one given as a parameter.
     * @param source Position to reproduce.
     */
    void setPosition(Position source){
        _x = source._x;
        _y = source._y;
    }


    /**
     * @brief Getter for vertical position.
     * @return int Return vertical position.
     */
    int getY() const
    {
        return _y;
    }

    /**
     * @brief Getter for horizontal position.
     * @return int Return horizontal position.
     */
    int getX() const
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
