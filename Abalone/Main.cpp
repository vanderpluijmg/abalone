#include "Model/position.hpp"
#include "Model/direction.h"
#include "Model/player.h"
#include "Model/abapro.h"
#include <iostream>
#include <string>


int main (void) {
    std::vector<std::string> resp;
    std::string move = "I8H7";
    for (int i = 0; i<(int)move.size();i++)
        if (i==2 || i==5)
            move.insert(i, " ");
    resp = AbaPro::getCommand(move);
    for (auto& x : resp)
        std::cout<<x<<std::endl;
}
