#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <Model/abapro.h>
#include "board.h"

class game
{
private:
    Board  _board;
public:
    game();

    /**
     * @brief Validates a move.
     * @param a Move utils to get move details
     * @return true if move is allowed
     */
    bool validateMove (moveUtils a);

    /**
     * @brief Validates a lateral move.
     * @param a moveUtils.
     * @return True if move is allowed.
     */
    bool validateLateralAndSameColor (moveUtils a);

    /**
     * @brief Checks if in given direction there is obstruction.
     * @param a move details.
     * @return True if no obstruction.
     */
    bool horizontalMoveCheckOne(moveUtils a, Position);

    /**
     * @brief Checks if all the given positions are of same color.
     * @param a move details.
     * @param inBetween Posistion in between pos1 and pos2.
     * @return True if all same color
     */
    bool allSameColor(moveUtils a, Position inBetween);

    bool allSameColor(std::vector<Position> p);

    /**
     * @brief Validates a line move.
     * @param a moveUtils.
     * @return True if move is allowed.
     */
    bool validateLineAndSameColor(moveUtils a);
};

#endif // GAME_H
