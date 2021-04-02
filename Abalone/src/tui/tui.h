#ifndef TUI_H
#define TUI_H
#include <iostream>
#include "game.h"

/**
 * @brief Terminal User Interface.
 */
class TUI{
public:
    /**
     * @brief Welcomes player.
     */
    static void welcomeBanner();

    /**
     * @brief Displays game board.
     * @param Game to display.
     */
    static void displayGameBoard(Game game);

    /**
     * @brief Displays a message.
     * @param message to display.
     */
    static void displayMessage(std::string message);

    /**
     * @brief Determines who's turn it is.
     * @param color to get opposite player.
     */
    static void whoseTurn(Color color);
};

#endif // TUI_H
