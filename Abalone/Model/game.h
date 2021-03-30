#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <Model/abapro.h>

class game
{
public:
    game();

    static bool validateMove (moveUtils a);

    static bool validateInOneLine (Position i, Position f);
};s

#endif // GAME_H
