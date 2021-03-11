#ifndef BALL_H
#define BALL_H
#include "list"
#include "position.hpp"
#include "map"

/**
 * @brief The Color enum represents the color of a ball.
 * The ball can either be white or black.
 */
enum Color  //Find way to print color.
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
    Position _p;
    Color _c;
    bool _onBoard;

public:
    /**
     * @brief Ball constructor with parametres.
     * @param ballPos Position of ball.
     * @param color Color of ball.
     */
    Ball(Position ballPos, Color color);

    /**
     * @brief Default Ball constructor
     */
    Ball();

    /**
     * @brief Copy constructor of Ball
     * @param playerBall
     */
    Ball(const Ball &playerBall);

    /**
     * @brief Gets status of onBoard.
     * @return True if ball is on board.
     */
    bool getOnBoardBall();

    /**
     * @brief sets ball on Board.
     * @param onBoard True if ball is on board.
     */
    void setOnBoardBall(bool onBoard);

    /**
     * @brief gets position of ball.
     * @return Position of current ball.
     */
    Position getPositionBall();

    /**
     * @brief sets position of Ball
     * @param p Position to set.
     */
    void setPosition(Position p);

    /**
     * @brief gets color of Ball.
     * @return Color of current ball.
     */

    Color getColorBall();

    /**
     * @brief sets color of ball
     * @param c Color of ball to set.
     */
    void setColorBall(Color c);

    /**
     * @brief fall procedure of Ball. Called upon
     * when a ball is ready to fall.
     */
    void fall();

    friend std::ostream &operator<<(std::ostream &stream, Ball &ball)
    {
        return stream << "Ball = " << ball.getPositionBall().getRow() << ", "<<ball.getPositionBall().getCol();
    }
};

#endif // BALL_H
