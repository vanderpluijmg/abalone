#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "player.h"
#include "map"
#include "ball.h"

class Game
{
private:
    std::map<Color, std::list<Ball>> players;
    Board board;
public:
    /**
     * @brief Default constructor for Game.
     */
    Game();
    /**
     * @brief Pseudo constructor for Board.
     * Initializes a game.
     */
    void startGame();

    void fallBall(Ball ball);
};

#endif // GAME_H
