#include "position.hpp"
#include "direction.h"
#include "player.h"

using namespace std;

int main () {
    Position p1(0,0);
    cout<<p1<<endl;
    Position p2 = p1.next(northWest);
    cout<<p2<<endl;
    Player g("Gregory", black);
    for (auto& x : g.getBalls()){
        cout<<x<<endl;
    }
}
