#include "abalonecore.h"

AbaloneCore::AbaloneCore(){
}

void AbaloneCore::start(){
    TUI::welcomeBanner();
    while(_end==0){
        TUI::displayGameBoard(_game);
        playTurn();
    }
    TUI::displayMessage("End of game");
}

void AbaloneCore::playTurn(){
    bool moveApproved = false;
    while(!moveApproved){
        TUI::getPlayerTurn(_turn);
        TUI::displayMessage("");
        MoveUtils givenMove = AbaPro::getCommand(TUI::askEntry());
        moveApproved=_game.applyMove(givenMove,_turn);
        if(!moveApproved)
            TUI::displayMessage("Wrong entry");
    }
    Color loser = _game.whoLost();
    loser==EMPTY?switchTurn():finish(loser);
}

void AbaloneCore::switchTurn(){
    _turn==WHITE? _turn=BLACK : _turn=WHITE;
}

Color AbaloneCore::getReturn(){
    return _turn;
}

bool AbaloneCore::getEndStatus(){
    return _end;
}

void AbaloneCore::finish(Color color){
    std::string loser = "";
    color == WHITE? loser.append("Player 1") : loser.append("Player 2");
    TUI::displayMessage(loser+" has lost the game !");
    _end=true;
}
