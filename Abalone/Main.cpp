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
    a =AbaPro::getCommand("C3C5D3");

    int deltaX;
    a.pos2.getRow()>a.pos1.getRow()? deltaX =2 : deltaX=-2;
    Position inBetween ((a.pos1.getCol()+(deltaX+1)), a.pos2.getRow());
    cout<<a.pos1<<endl;
    cout<<a.pos2<<endl;
    cout<<inBetween;
    }
