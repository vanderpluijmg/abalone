#ifndef _ABAPRO_H
#define _ABAPRO_H
#include "direction.h"
#include "position.hpp"
#include <vector>
#include <map>
#include <string>

class AbaPro
{
public:
    /**
 * @brief Asks for input from the user and returns a vector of Strings
 * 
 * @return std::vector<std::string> the representation  of the command that can be translated to a Position or a Ball object.
 */
    std::vector<std::string> getCommand();

    /**
 * @brief Receives a representation of the given command and extracts the desired direction for the movement
 * 
 * @param source the command to analyse.
 * @return Direction the resulting direction
 */
    Direction getDirection(std::vector<std::string> source);
    /**
 * @brief Moves the concerned Ball object that can be found on given Positions in the given Direction while verifying the validity of the move.
 * 
 * @param moves 
 */
    void moveBall(std::map<std::vector<Position>, Direction> moves);
};

#endif //_ABAPRO_H
