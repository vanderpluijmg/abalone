#ifndef _ABAPRO_H
#define _ABAPRO_H
#include "direction.h"
#include "position.hpp"
#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdio>
#include <ctype.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <string>

/**
 * @brief All utils needed to preform a move.
 */
struct MoveUtils {
    Position pos1 = Position(-5,-5);
    Position pos2 = Position(-15,-15);//optional
    Direction dir;
};
/**
 * @brief The AbaPro class translates entries given by the user to data required by the program to be in use.
 */
class AbaPro{
public:

    /**
     * @brief Interacts with user to get his move command.
     * @return All the data required to do a move represented by the MoveUtils structure.
     */
    static MoveUtils getCommand(std::string);

    /**
     * @brief Extracts the direction from two given Positions.
     * @return Direction in wich to go to.
     */
    static Direction getDirection (Position init, Position final);

    /**
     * @brief Tokenises a string with a delimeter in a new vector.
     * @param move String to tokenise.
     * @param space The given delimiter which determines where to split.
     * @param response Each token goes into response.
     */
    static void split (const std::string& move, const std::string& space, std::vector<std::string>& response);

    /**
     * @brief Takes a string and turns it into a Position object.
     * @param command string format to turn into position.
     * @return Postion that was determined.
     */
    static Position getPosition (const std::string& command);

    /**
     * @brief Adds a position to the utils.
     * @param a MoveUtils to which the position will be added to.
     * @param p A given Position to add to the MoveUtils object.
     */
    static void addPositionUtils (MoveUtils& a, Position p);

    /**
     * @brief parseString Parses the string and verifies if given entries match the desired pattern. Desired Pattern : One letter groing from A to I followed by a number going from 1 to 9.
     * @param command The string to verify.
     * @return true if the given string matches the pattern.
     * @return false otherwise.
     */
    static bool parseString (const std::vector<std::string>& command);
};

#endif //_ABAPRO_H
