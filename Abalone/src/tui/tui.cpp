#include "tui.h"

void TUI::welcomeBanner(){
    displayMessage("---------------------------");
    displayMessage("Welcome to Abalone");
    displayMessage("---------------------------");
}

void TUI::displayGameBoard(Game game){
    std::cout<<game.getBoard().toString()<<std::endl;
}

void TUI::displayMessage(std::string message){
    std::cout<<message<<std::endl;
}

void TUI::whoseTurn(Color color){
    std::string turn = "";
    if(color == WHITE) turn.append("Player 1");
    else turn.append("Player 2");
    TUI::displayMessage(turn+" has to play");
}
