#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <Model/abapro.h>
#include "board.h"
/**
 * @brief The game class
 */
class game
{
private:
    Board  _board;
public:
    game();

    /**
     * @brief Validates a move.
     * @param a MoveUtils to get move details.
     * @return true if the desired move found in the MoveUtils object is allowed
     */
    bool validateMove (MoveUtils a);

    /**
     * @brief Validates a lateral move.
     * @param a moveUtils.
     * @return true if move is allowed.
     */
    bool validateLateralAndSameColor (MoveUtils a);

    /**
     * @brief Checks if there is any obstruction in given direction.
     * @param a MoveUtils object.
     * @return True if no obstructions.
     */
    bool horizontalMoveCheckOne(MoveUtils a, Position);

    /**
     * @brief Checks if all the given positions are of same color.
     * @param a MoveUtils object.
     * @param inBetween Posistion is in between pos1 and pos2 that can be found in MoveUtil object.
     * @return True if all of them are of the same color.
     */
    bool allSameColor(MoveUtils a, Position inBetween);

    /**
     * @brief Validates a line move.
     * @param a MoveUtils object.
     * @return True if move is allowed.
     */
    bool validateLineAndSameColor(MoveUtils a);
};

#endif // GAME_H
