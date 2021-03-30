#include "position.hpp"
#include "direction.h"
#include "player.h"

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
