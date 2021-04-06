#include "tui.h"

void TUI::welcomeBanner(){
    displayMessage("---------------------------");
    displayMessage("Welcome to Abalone");
    displayMessage("---------------------------");
}

void TUI::displayGameBoard(Game game){
    std::cout<<game.getBoard().toString();
}

void TUI::displayMessage(std::string message){
    std::cout<<message<<std::endl;
}

void TUI::getPlayerTurn(Color color){
    std::string turn = "";
    color == WHITE? turn.append("Player 1") : turn.append("Player 2");
    TUI::displayMessage("It is " +turn+"'s to play");
}

std::string TUI::askEntry (){
    std::string command="";
    std::cin>> command;
    return command;
}
