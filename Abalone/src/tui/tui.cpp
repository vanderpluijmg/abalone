#include "tui.h"

void TUI::displayGameBoard(Game game){
    std::cout<<game.getBoard().toString()<<std::endl;
}

void TUI::displayMessage(std::string message){
    std::cout<<message<<std::endl;
}
