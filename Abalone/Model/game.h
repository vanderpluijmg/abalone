#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <Model/abapro.h>

class game
{
public:
    game();

    static bool validateMove (moveUtils a);

    static bool validateLateralAndSameColor (Position i, Position f);

    static bool horizontalMoveCheckOne(moveUtils a);

    static Position getInBetweenH(Position i, Position f);
};

#endif // GAME_H
