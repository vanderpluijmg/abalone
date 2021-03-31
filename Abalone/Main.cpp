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
    Board efd;
    efd.getInitBoard();
    cout<<efd.toString();
}
