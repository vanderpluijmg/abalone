#ifndef HEXAGON_HPP
#define HEXAGON_HPP

#include "position.hpp"
#include "color.hpp"

class Hexagon
{
private:
    Position _position;
    Color _marbleColor;

public:
    /**
     * @brief Default Hexagon constructor
     */
    Hexagon(){
    }

    /**
     * @brief Hexagon
     * @param color
     * @param x
     * @param y
     */
    Hexagon(Color color, int x, int y)
    {
        _marbleColor = color;
        _position = Position(x, y);
    }

    /**
     * @brief Gets color of hexagon.
     * @return Returns color of current hexagon.
     */
    Color getMarbleColor()
    {
        return _marbleColor;
    }

    /**
     * @brief Sets a new color to the hexagon.
     * @param color New color of hexagon.
     */
    void setMarbleColor(Color color)
    {
        _marbleColor = color;
    }

    /**
    * @brief Sets the hexagon as EMPTY.
    */
    void setEmpty()
    {
        _marbleColor = EMPTY;
    }

    /**
     * @brief Gets position of Hexagon.
     * @return Position of current hexagon.
     */
    Position getPosition()
    {
        return _position;
    }
};

#endif // HEXAGON_H
