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
    *@brief Interacts with user to get his move command.
    *@return String of command.
    **/
    std::vector<std::string> getCommand();

    /**
     * @brief Extracts the direction from a vector of String.
     * @return
     */
    Direction getDirection (std::vector<std::string>);

};

#endif //_ABAPRO_H
