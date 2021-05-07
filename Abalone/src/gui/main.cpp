#include "gui.h"
#include "abalonecore.h"
#include "../tui/tui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    double rad = 50;
    QApplication b(argc, argv);
    Game game = Game();

    GUI w = GUI(nullptr,&game,rad);
    w.updateDisplay();
    w.show();
    w.resize(rad*22.5, rad*18);
    return b.exec();
}
