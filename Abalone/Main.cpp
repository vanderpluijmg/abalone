#include "Model/position.hpp"
#include "Model/direction.h"
#include "Model/player.h"
#include "Model/abapro.h"
#include <iostream>
#include <string>

using namespace::std;

int main (void) {
    std::vector<std::string> command;
    moveUtils a;
<<<<<<< HEAD
    a =AbaPro::getCommand("C3C5D3");
    cout<<a.pos1<<endl;
    cout<<a.pos2<<endl;
    cout<<a.dir.getDirection();
=======
    AbaPro::addPositionUtils(a,AbaPro::getPosition("I8"));
    //a=AbaPro::getCommand(move);
    std::cout<<a.pos1<<std::endl;
    std::cout<<55;
>>>>>>> 1b15062c22834194039ce6bb917339d7cca71f7e
    }
