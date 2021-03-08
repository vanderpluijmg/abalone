#include "position.h"

Position::Position()
{
    class Position
    {
    private:
        int col, row;

    public:
        Position(int x, int y)
        {
            col = x;
            row = y;
        }
        Position()
        {
            row = 0;
            col = 0;
        }
        Position(const Position &pos) { row = pos.row, col = pos.col; }
        void next()
        {
        }
        int getRow()
        {
            return row;
        }
        int getColumn()
        {
            return col;
        }
    };
}
