#include "mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <cmath>
#include <QPen>


#include "hexacell.h"
#include "ball.h"
#include "point.hpp"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QGraphicsScene  * scene = new QGraphicsScene();
    Game game = Game();

    addGameBoardAbalone(game.getBoard(),scene);
    scene->setBackgroundBrush(Qt::gray);

    QGraphicsView * view = new QGraphicsView(scene);

    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::TextAntialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);

    view->update();

    resize(1000, 800);

    this->setCentralWidget(view);
}

MainWindow::~MainWindow()
{
}

void MainWindow::addGameBoardAbalone(Board board, QGraphicsScene  * scene){
    for (int i = 0; i < 9; i++) {
        for (int j = 0;j<9 ; j++) {
            if(board.isOnBoard(Position(j,i))){
                scene->addItem(new HexaCell( j, i));
                Color color = board.getColor(Position(j,i));
                if (color == BLACK)scene->addItem(new Ball( j, i,color));
                if (color == WHITE)scene->addItem(new Ball( j, i,color));

            }
        }
    }
}
