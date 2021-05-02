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
    graphics_scene  * foreground = new graphics_scene();
    graphics_scene  * background = new graphics_scene();

    Game game = Game();

    addGameBoardAbalone(game.getBoard(),background);
    addBallsAbalone(game.getBoard(),foreground);

    foreground->setBackgroundBrush(Qt::gray);

    QGraphicsView * view = new QGraphicsView(foreground);
    view->setScene(foreground);
    foreground->set_background_scene(background);

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

void MainWindow::addGameBoardAbalone(Board board, graphics_scene  * scene){
    for (int i = 0; i < 9; i++) {
        for (int j = 0;j<9 ; j++) {
            if(board.isOnBoard(Position(j,i))){
                scene->addItem(new HexaCell( j, i));
            }
        }
    }
}

void MainWindow::addBallsAbalone(Board board, graphics_scene  * scene){
    for (int i = 0; i < 9; i++) {
        for (int j = 0;j<9 ; j++) {
            if(board.isOnBoard(Position(j,i))){
                Color color = board.getColor(Position(j,i));
                if (color == BLACK)scene->addItem(new Ball( j, i,color));
                if (color == WHITE)scene->addItem(new Ball( j, i,color));
            }
        }
    }
}
