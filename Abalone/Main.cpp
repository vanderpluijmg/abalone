#include "Model/position.hpp"
#include "Model/direction.h"
#include "Model/player.h"
#include "Model/abapro.h"
#include <iostream>
#include <string>
#include "Model/game.h"

using namespace::std;

int main (void) {
    std::vector<std::string> command;
    moveUtils a;
    a =AbaPro::getCommand("C3C5D3");
    cout<<a.pos1;
}
