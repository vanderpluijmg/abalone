#include "abalonecore.h"
AbaloneCore::AbaloneCore(){
}

void AbaloneCore::start(){
    TUI::welcomeBanner();
    while(_end!=true){
        turnPlay();
    }
}

void AbaloneCore::turnPlay(){
    bool movedWell = false;
    while(!movedWell){
        //faire l'entree de l'utilisateur
        //verifier avec validate move
        //validate move renvoie un chiffre par rapport a quel type de move devra etre effectue
        //movedWell=_game.applyMove();
}
        Color loser = _game.whoLost();
        if(loser != EMPTY);
        else switchTurn();
}

void AbaloneCore::switchTurn(){
    if(_turn==WHITE)_turn=BLACK;
    else _turn=WHITE;
}

Color AbaloneCore::getTour(){
    return _turn;
}

bool AbaloneCore::getEndStatus(){
    return _end;
}

void AbaloneCore::finish(Color color){
    std::string loser = "";
    if(color == WHITE) loser.append("Player 1");
    else loser.append("Player 2");
    TUI::displayMessage(loser+" lost the game !");
    _end=true;
}
