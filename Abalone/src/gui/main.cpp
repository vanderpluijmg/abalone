#include "gui.h"
#include "abalonecore.h"
#include "../tui/tui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    //AbaloneCore a;
    double rad = 50;
    QApplication b(argc, argv);
    Game game = Game();

    GUI w = GUI(nullptr,&game,rad);//(nullptr,&game,60)
    //    MoveUtils move = MoveUtils();
    //    AbaPro::addPosAndDirToUtils(move,Position(4,0),Direction(-1,1));
    //    game.applyMove(move,Color::WHITE);
    //    std::cout<<game.getBoard().toString()<<std::endl;
    w.updateDisplay();
    w.show();
    w.resize(rad*22.5, rad*18);
    return b.exec();
}
