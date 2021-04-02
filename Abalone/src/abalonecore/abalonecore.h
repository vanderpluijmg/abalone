#ifndef ABALONECORE_H
#define ABALONECORE_H
#include "game.h"
#include "../tui/tui.h"

class AbaloneCore{
private:
    Game _game=Game();
    bool _end=false;
    Color tour=WHITE;
public:
    void start();

    bool turnPlay();

    bool getEndStatus();

    void finish();

    void setTour();

    Color getTour();
};

#endif // ABALONECORE_H
