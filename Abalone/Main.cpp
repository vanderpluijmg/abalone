#include "Model/position.hpp"
#include "Model/direction.h"
#include "Model/player.h"
#include "Model/abapro.h"
#include <iostream>
#include <string>
#include "Model/game.h"
#include "Model/board.h"

using namespace::std;

int main (void) {
    std::vector<std::string> command;
    moveUtils a;
    a =AbaPro::getCommand("G2E2D3");
    cout<<a.pos1<<std::endl;
    cout<<a.pos2<<std::endl;
    cout<<game::validateVerticalAndSameColor(a.pos1,a.pos2);
}
