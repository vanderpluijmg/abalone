#include "position.hpp"
#include "direction.h"

using namespace std;

int main () {
    Position p1(0,0);
    cout<<p1<<endl;
    Position p2 = p1.next(northWest);
    cout<<p2<<endl;
}
