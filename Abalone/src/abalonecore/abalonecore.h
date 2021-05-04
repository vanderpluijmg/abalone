#ifndef ABALONECORE_H
#define ABALONECORE_H
#include "game.h"
#include "../tui/tui.h"
#include "abapro.h"

/**
 * @brief The AbaloneCore represents a Controller.
 */
class AbaloneCore{
private:

    Game _game=Game();
    TUI _tui;
    bool _end=false;
    Color _turn=WHITE;

public:

    /**
     * @brief AbaloneCore default constructor.
     */
    AbaloneCore();

    /**
     * @brief Pseudo-Constructor for AbaCore.
     */
    void  start();

    /**
     * @brief Defines how a player should play his turn.
     */
    void playTurn();

    /**
     * @brief Getter for _end variable.
     * @return End variable value.
     */
    bool getEndStatus();

    /**
     * @brief Determines how a players looses.
     * @param color Color of player that lost.
     */
    void finish(Color color);

    /**
     * @brief Switches turn of players.
     */
    void switchTurn();

    /**
     * @brief Getter for return variable.
     * @return
     */
    Color getReturn();
};

#endif // ABALONECORE_H
