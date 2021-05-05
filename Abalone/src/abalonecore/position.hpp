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
    Position next( Direction direction) const
    {
        return Position(getX() + direction.getDeltaX(), getY() + direction.getDeltaY());
    }

    //    /**
    //     * @brief Setter for position
    //     * @param target Position to modify.
    //     * @param source Position to reproduce.
    //     */
    //    void static setPosition(Position &target, Position source){
    //        target._x=source._x;
    //        target._y=source._y;
    //    }

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
     * @brief setPosition sets the current position to the same as the one given as a parameter.
     * @param source Position to reproduce.
     */
    void setPosition( Position source)
    {
        _x = source._x;
        _y = source._y;
    }

    void setPosition (int x, int y)
    {
        _x= x;
        _y=y;
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

    /**
     * @brief operator == Compares if 2 position have the same coordinates.
     * @param rhs A position to compare.
     * @return true if identical.
     * @return false if different.
     */
    bool operator==(const Position & rhs) const
    {
        return (_x==rhs._x && _y==rhs._y);
    }

    bool operator !=(const Position & rhs) const
    {
        return (*this == rhs);
    }

};
#endif // POSITION_H
