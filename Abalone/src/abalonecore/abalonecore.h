#ifndef ABALONECORE_H
#define ABALONECORE_H
#include "game.h"
#include "../tui/tui.h"

class Controller{
private:
    Game _game=Game();
    bool _finished=false;
    Color tour=BLACK;
public:
    void start();


};

#endif // ABALONECORE_H
