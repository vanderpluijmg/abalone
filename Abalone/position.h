#ifndef POSITION_H
#define POSITION_H

class Position
{
private:
    int col, row;

public:
    Position(int x, int y);
    Position();
    Position(const Position &pos);
    void next();
    int getRow();
    int getColumn();
};
#endif // POSITION_H
