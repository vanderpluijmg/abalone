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
    MoveUtils a;
    a = AbaPro::getCommand("I8H7"); //Direction verification.
    game game;
    bool ax = game.validateMove(a);
    cout<<ax;
}
