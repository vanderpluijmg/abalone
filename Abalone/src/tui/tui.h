#ifndef TUI_H
#define TUI_H
#include <iostream>
#include "../abalonecore/game.h"


class TUI{
    void displayGameBoard(Game game);
    void displayMessage(std::string message);
};

#endif // TUI_H
