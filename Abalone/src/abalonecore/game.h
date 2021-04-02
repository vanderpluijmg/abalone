#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include "abapro.h"
#include "board.h"
/**
 * @brief The game class
 */
class Game
{
private:
    Board  _board;
    int _piecesWhite=14;
    int _piecesBlack=14;

public:
    Game();

    /**
     * @brief Validates a move.
     * @param a MoveUtils to get move details.
     * @return true if the desired move found in the MoveUtils object is allowed
     */
    int validateMove (const MoveUtils& a,Color player);

    /**
     * @brief Validates a lateral move.
     * @param a moveUtils.
     * @return true if move is allowed.
     */
    bool validateLateralAndSameColor (const MoveUtils& a);

    /**
     * @brief Checks if there is any obstruction in given direction.
     * @param a MoveUtils object.
     * @return True if no obstructions.
     */
    bool checkAllCaseEmtpy(const MoveUtils& a, Position);

    /**
     * @brief Checks if all the given positions are of same color.
     * @param a MoveUtils object.
     * @param inBetween Posistion is in between pos1 and pos2 that can be found in MoveUtil object.
     * @return True if all of them are of the same color.
     */
    bool allSameColor(const MoveUtils& a, Position inBetween);

    /**
     * @brief Validates a line move.
     * @param a MoveUtils object.
     * @return True if move is allowed.
     */
    bool validateLinearAndSameColor(const MoveUtils& a);

    /**
     * @brief getBoard Getter for the game board.
     * @return A Board object.
     */
    Board getBoard();

    bool applyMove(MoveUtils moves,Color player);

    void loseBall(Color playerl);

    Color whoLost();

    bool applyMoveLinear(const MoveUtils& a);
    bool applyMoveLateral(const MoveUtils& a);

};

#endif // GAME_H
