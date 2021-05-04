#include "gui.h"
#include "abalonecore.h"
#include "../tui/tui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //AbaloneCore a;
    QApplication b(argc, argv);
    Game game = Game();
    MoveUtils move = MoveUtils();
    AbaPro::addPosAndDirToUtils(move,Position(4,0),Direction(-1,1));
    game.applyMove(move,Color::WHITE);
    GUI w = GUI(nullptr,&game);
    std::cout<<game.getBoard().toString()<<std::endl;


    w.show();
    return b.exec();
}
