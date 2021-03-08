#ifndef BALL_H
#define BALL_H
#include "position.h"

class Ball
{
private:
    Position p;
    Color C;
public:
    Ball(Position BallPos, Color color);
};

#endif // BALL_H
