#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "player.h"
#include "map"

class Game
{
private:
    std::map<Color, Player> _players;
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
        //Initializes two players with l.
        //Initializes Board.
        //Game::_board.initBoard();
        //Initialize every player with its name and its set of colors.
    }
    void fallBall(Player player)
    {
        player.lostBall();
        //players.at(BLACK).;
        //In map player find player with correct color ball and reduce his count of balls
    }
};

#endif // GAME_H