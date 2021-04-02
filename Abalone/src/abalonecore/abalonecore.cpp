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
        std::string command="";
        std::cin>>command;        //faire l'entree de l'utilisateur
        MoveUtils possibleMove = AbaPro::getCommand(command);//extraire le  mouvement
        movedWell=_game.applyMove(possibleMove,_turn);//valider si le mouvement a bien ete fait sinon relance la boucle
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
