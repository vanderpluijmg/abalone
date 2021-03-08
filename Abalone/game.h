#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "player.h"
#include "vector"

class Game
{
private:
    std::vector<Player> Players;
    Board board;

public:
    /**
     * @brief Pseudo constructor for Board.
     * Initializes a game.
     */
    void initGame()
    {
    }
};

#endif // GAME_H
