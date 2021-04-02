#ifndef TUI_H
#define TUI_H
#include <iostream>
#include "../abalonecore/game.h"


class TUI{
public:
    static void welcomeBanner();
    static void displayGameBoard(Game game);
    static void displayMessage(std::string message);
    static void whoseTurn(Color color);
};

#endif // TUI_H
