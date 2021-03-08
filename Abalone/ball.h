#ifndef BALL_H
#define BALL_H
#include "position.h"

/**
 * @brief The Color enum represents the color of a ball.
 * The ball can either be white or black.
 */
enum Color
{
    white,
    black
};

/**
 * @brief The Ball class represents a ball on the board.
 */
class Ball
{
private:
    Position p;
    Color c;

public:
    /**
     * @brief Ball constructor with parametres.
     * @param ballPos Position of ball.
     * @param color Color of ball.
     */
    Ball(Position ballPos, Color color)
    {
        p = ballPos;
        c = color;
    }
    /**
     * @brief Default Ball constructor
     */
    Ball(){};
    /**
     * @brief Copy constructor of Ball
     * @param playerBall
     */
    Ball(const Ball &playerBall)
    {
        p = playerBall.p;
        c = playerBall.c;
    };
    Position getPositionBall()
    {
        return p;
    }
    Color getColorBall()
    {
        return c;
    }
    void setPosition(Color c)
    {
        c = c;
    }
};

#endif // BALL_H
