#include "gui.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <cmath>
#include <QPen>


#include "hexacell.h"
#include "ball.h"
#include "point.hpp"

/**
 * @brief Graphical User Interface.
 */
GUI::GUI(QWidget *parent,Game* game)
    : QMainWindow(parent),    game(game)
{
    addGameBoardAbalone(game->getBoard(),background,Qt::gray);
    addBallsAbalone(game->getBoard(),balls);
    addGameBoardAbalone(game->getBoard(),foreground,Qt::transparent);

    QGraphicsView * view = new QGraphicsView(foreground);
    foreground->set_background_scene(balls);
    balls->set_background_scene(background);
    ballsUpdate();
    QString matchText = "Player 1 vs Player 2";
    QGraphicsTextItem * match = new QGraphicsTextItem();
    match->setPlainText(matchText);
    match->setPos(425, 0);
    foreground->addItem(match);
    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::TextAntialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);

    view->update();

    resize(1000, 800);

    this->setCentralWidget(view);
}

GUI::~GUI()
{
}

void GUI::addGameBoardAbalone(Board board, graphics_scene  * scene,Qt::GlobalColor color){
    for (int i = 0; i < 9; i++) {
        for (int j = 0;j<9 ; j++) {
            if(board.isOnBoard(Position(j,i))){
                scene->addItem(new HexaCell( j, i,color));
            }
        }
    }
}

void GUI::addBallsAbalone(Board board, graphics_scene  * scene){
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
void GUI::ballsUpdate(){
    for(int i =balls->items().size()-1;i>=0;i--){
        {
            delete this->balls->items().at(i);
        }
    }

    std::cout<<game->getBoard().toString()<<std::endl;
    addBallsAbalone(game->getBoard(),balls);
}
