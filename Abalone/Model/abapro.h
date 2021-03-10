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

    std::vector<std::string> getCommand();

    Direction getDirection(std::vector<std::string> source);

    void moveBall(std::map<std::vector<Position>, Direction> moves);
};

#endif //_ABAPRO_H
