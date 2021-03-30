#include "Model/position.hpp"
#include "Model/direction.h"
#include "Model/player.h"
#include "Model/abapro.h"
#include <iostream>
#include <string>


int main (void) {
    std::vector<std::string> resp;
    std::string move = "I8H7";
    moveUtils a;
    AbaPro::addPositionUtils(a,AbaPro::getPosition("I8"));
    //a=AbaPro::getCommand(move);
    std::cout<<a.pos1<<std::endl;
    std::cout<<55;
    }
