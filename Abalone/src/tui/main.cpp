#include "../abalonecore/abalonecore.h"
#include "../abalonecore/direction.h"
#include "../abalonecore/player.h"
#include "../abalonecore/abapro.h"
#include <iostream>
#include <string>
#include "../abalonecore/game.h"
#include "../abalonecore/board.h"

using namespace std;
int main (void) {
    AbaloneCore a;a.start();/*
    MoveUtils a = AbaPro::getCommand("I8H7"); //Direction verification.
    Game af = Game();
    cout<<af.getBoard().toString()<<endl;
    cout<<"aaaaaaaaaaaaaaaaaa"<<endl;
    cout<<af.getBoard().isOnBoard(Position(8,9))<<endl;
    cout<<af.getBoard().getColor(Position(8,9))<<endl;
    cout<<"aaaaaaaaaaaaaaaaaa"<<endl;
    cout<<a.pos1<<endl;
    cout<<a.pos2<<endl;
    cout<<a.dir<<endl;
    cout<<af.validateMove(a,BLACK)<<endl;
    cout<<"aaaaaaaaaaaaaaaaaa"<<endl;
    cout<<AbaPro::checkPositionsInCommand(std::vector<string>{"I1"})<<endl;*/

    //ne pas oublier dans le validate move que il doit etre applique sur des pions de la couleur du joueur.
    //aller voir modif bool Game::validateLateralAndSameColor(const MoveUtils& a) dis ce que t'en pense
}
