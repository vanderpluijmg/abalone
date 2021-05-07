#ifndef COLOR_HPP
#define COLOR_HPP
/**
 * @brief The Color enum represents all of the possible Values for the Hexagon in a game board.
 * WHITE is for white games pieces.
 * BLACK is for black game pieces.
 * EMPTY is for when the Hexagon is empty but a game piece can be positioned on it.
 * OUTOFBOUND is treated as out of the board so if a game piece goes there it will fall from the game board.
 */
enum Color
{
    WHITE,
    BLACK,
    EMPTY,
    OUTOFBOUND
};

#endif // COLOR_HPP
