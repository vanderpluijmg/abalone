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
    Position pos1 = Position(-5,-5);
    Position pos2 = Position(-15,-15);;//optional
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
     * @return Direction in wich to go to.
     */
    static Direction getDirection (Position init, Position final);

    /**
     * @brief Tokenises a string with a delimeter in a new vector.
     * @param move String to tokenise.
     * @param space Split after every delimiter.
     * @param response Each token goes in to response.
     */
    static void split (const std::string& move, const std::string& space, std::vector<std::string>& response);

    /**
     * @brief Takes a string and turns it to know posisitons.
     * @param command string format to turn into position
     */
    static Position getPosition (const std::string command);

    /**
     * @brief Adds a position to the utils.
     * @param a utils to add position to.
     * @param p Position to add to utils.
     */
    static void addPositionUtils (moveUtils& a, Position p);
};

#endif //_ABAPRO_H
