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
    moveUtils a;
    a = AbaPro::getCommand("C3C5D3"); //Direction verification.
    game game;
    cout<<game.validateLineAndSameColor(a);
}
