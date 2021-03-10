#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "player.h"
#include "map"
#include "ball.h"

class Game
{
private:
    std::map<Color, std::list<Ball>> _players;
    Board _board;

public:
    /**
     * @brief Default constructor for Game.
     */
    Game()
    {
    }
    /**
     * @brief Pseudo constructor for Board.
     * Initializes a game.
     */
    void startGame()
    {
        Game::_board.initBoard();
        //Initialize every player with its name and its set of colors.
    }
    void fallBall(Ball ball)
    {
        ball.fall();
        //players.at(black).;
        //In map player find player with correct color ball and reduce his count of balls
    }
};

#endif // GAME_H
