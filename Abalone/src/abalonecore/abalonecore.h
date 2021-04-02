#ifndef ABALONECORE_H
#define ABALONECORE_H
#include "game.h"
#include "../tui/tui.h"
#include "abapro.h"

class AbaloneCore{
private:

    Game _game=Game();
    TUI _tui;
    bool _end=false;
    Color _turn=WHITE;

public:
    AbaloneCore();
    void  start();

    void turnPlay();

    bool getEndStatus();

    void finish(Color color);

    void switchTurn();

    Color getTour();
};

#endif // ABALONECORE_H
