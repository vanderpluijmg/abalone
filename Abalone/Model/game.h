#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <Model/abapro.h>

class game
{
public:
    game();


    static bool validateMove (moveUtils a);

    static bool validateHorizontalAndSameColor (Position i, Position f);

    static bool horizontalMoveCheckOne(moveUtils a);

    static bool validateSingleMove(moveUtils a);

    static Position getInBetweenH(Position a, Position b);
};

#endif // GAME_H
