#ifndef _ABAPRO_H
#define _ABAPRO_H
#include "direction.h"
#include "position.hpp"
#include <vector>
#include <map>
#include <string>

/**
 * @brief All utils needed to preform a move.
 */
struct moveUtils {
    Position pos1;
    Position pos2;//optional
    Direction dir;
};

class AbaPro{
public:
    /**
    *@brief Interacts with user to get his move command.
    *@return String of command.
    **/
    static moveUtils getCommand(std::string);

    /**
     * @brief Extracts the direction from a vector of String.
     * @return
     */

    static Direction getDirection (Position init, Position final);

    static void split (const std::string& str, const std::string& delim, std::vector<std::string>& parts);

    /**
     * @brief Takes a string and turns it to know posisitons.
     * @param command string format to turn into position
     */
    static Position getPosition (const std::string command);
};

#endif //_ABAPRO_H
