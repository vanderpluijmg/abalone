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
    Board  _board = Board();
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
     * @brief getBoard Getter for the game board.
     * @return A Board object.
     */
    Board getBoard();

    /**
     * @brief Applies a move to a player.
     * @param moves Move to apply.
     * @param player Player to apply moves too.
     * @return True if move has been applied.
     */
    bool applyMove(MoveUtils moves,Color player);

    /**
     * @brief loseBall Adds a lost ball to a player.
     * @param playerl Color of player who lost his ball.
     */
    void loseBall(Color playerl);

    /**
     * @brief Determines who lost.
     * @return Color of player if someone lost.
     */
    Color whoLost();

    /**
     * @brief Creates a vector of all balls that are implicated in the move.
     * @param Position of first ball to move.
     * @param playerColor Color of first ball.
     * @param d Direction in which to go.
     * @return  A vector of all balls that will move.
     */
    std::vector<Position> createAttackGroup(Position begin, Color playerColor, Direction d);

    /**
     * @brief Applies a linear move if move is valid.
     * @param defenseGroup Vector of defense balls.
     * @param attackGroup Vector of attack balls.
     * @param d Direction in which to move.
     * @param playerColor Color of player that is moving
     * @return True if move is applied.
     */
    bool applyLinearMove (std::vector<Position> defenseGroup, std::vector<Position> attackGroup, Direction d, Color playerColor);

    /**
     * @brief Applies a linear move.
     * @param a Moves to apply.
     * @param color Color to apply moves too.
     * @return True if move has been applied.
     */
    bool validateLinearAndSameColor(const MoveUtils& a);

    /**
     * @brief Creates defend group and applies move.
     * @param a Getter for attacking moves.
     * @param begin First position of defending group.
     * @param playerColor Color of the defending player.
     * @return True if move can be done and has been applied.
     */
    bool createDefendGroup(const MoveUtils& a, Position begin, Color playerColor, const std::vector<Position>&);

    /**
     * @brief Applies a lateral move.
     * @param a Moves to apply.
     * @param color Color to apply moves too.
     * @return True if move has been applied.
     */
    bool applyLateralMove(const MoveUtils& a,Color color, Position);

    /**
     * @brief Finds position between 2 positions
     * @param a Positions to get inBetween from.
     * @return Position that is in between
     */
    Position findPositionBetween(const MoveUtils& a);

};

#endif // GAME_H
