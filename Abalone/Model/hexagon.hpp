#ifndef HEXAGON_H
#define HEXAGON_H

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
    Hexagon();

    /**
     * @brief Gets color of hexagon.
     * @return Returns color of current hexagon.
     */
    Color getColor (){
        return _marbleColor;
    }

    /**
     * @brief Sets a new color to the hexagon.
     * @param color New color of hexagon.
     */
    void setColor(Color color){
        _marbleColor = color;
    }

    /**
     * @brief Gets position of Hexagon.
     * @return Position of current hexagon.
     */
    Position getPosition (){
        return _position;
    }
};

#endif // HEXAGON_H
