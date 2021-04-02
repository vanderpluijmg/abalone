#ifndef _ABAPRO_H
#define _ABAPRO_H
#include "direction.h"
#include "position.hpp"
#include <cstring>
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <vector>
#include <string>

/**
 * @brief All utils needed to preform a move.
 */
struct MoveUtils
{
    Position pos1 = Position(-1,-1);
    Position pos2 = Position(-1,-1);
    Direction dir = Direction(0,0);
};

/**
 * @brief The AbaPro class translates entries given by the user to data required by the program to be in use.
 */
class AbaPro
{
private:

    /**
     * @brief checkCommandSyntaxValidity
     * @param command
     * @return
     */
    static bool checkCommandSyntaxValidity(const std::string& command);

public:

    /**
     * @brief Tokenises a string into a new vector.
     * @param move String to tokenise.
     * @param response Each token goes into response.
     */
    static void commandTok ( std::string& move, std::vector<std::string>& response);

    /**
     * @brief Interacts with user to get his move command.
     * @return All the data required to do a move represented by the MoveUtils structure.
     */
    static MoveUtils getCommand(std::string);

    /**
     * @brief checkPositionsInCommand Checks if positions given in the command by the user comply to the required data.
     * @param command A given command.
     * @return true if it matches.
     * @return false if it does not match.
     */
    static bool checkPositionsInCommand (const std::vector<std::string>& command);

    /**
     * @brief Adds a position to the utils.
     * @param a MoveUtils to which the position will be added to.
     * @param p A given Position to add to the MoveUtils object.
     * @param dir A given Direction to add to the MoveUtils object.
     */
    static void addPosAndDirToUtils (MoveUtils& a, Position p,Direction dir);

    /**
     * @brief Adds 2 positions and a direction to the utils.
     * @param a MoveUtils to which the position will be added to.
     * @param p1 A given Position to add to the MoveUtils object.
     */
    /**
     * @brief add2PosAndDirToUtils Adds 2 positions and a direction to the utils.
     * @param a MoveUtils to which the positions will be added to.
     * @param p1 A given Position to add to the MoveUtils object.
     * @param p2 A second Position to add to the MoveUtils object.
     * @param dir A given Direction to add to the MoveUtils object.
     */
    static void add2PosAndDirToUtils (MoveUtils& a, Position p1, Position p2,Direction dir);

    /**
     * @brief Takes a string and turns it into a Position object.
     * @param command string format to turn into position.
     * @return Postion that was determined.
     */
    static Position getPosition (const std::string& command);

    /**
     * @brief Extracts the direction from two given Positions.
     * @return Direction in wich to go to.
     */
    static Direction getDirection (Position init, Position final);


};

#endif //_ABAPRO_H
