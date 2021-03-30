#include "Model/position.hpp"
#include "Model/direction.h"
#include "Model/player.h"

using namespace std;

int main (void) {
    Position p1(0,0);
    cout<<p1<<endl;
    Position p2 = p1.next(northWest);
    cout<<p2<<endl;
    Position d = Position(5,4);
    cout<<d.getCol();
    cout<<d.getRow();
}
