#ifndef GUI_H
#define GUI_H

#include <QGraphicsScene>
#include <QMainWindow>
#include "../abalonecore/game.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cmath>
#include <QPen>

#include "hexacell.h"
#include "ball.h"
#include "point.hpp"
#include "graphics_scene.hpp"

class GUI : public QMainWindow
{
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr,Game*g=nullptr);
    void addGameBoardAbalone(Board board, graphics_scene  * scene,Qt::GlobalColor color);
    void addBallsAbalone(Board board, graphics_scene  * scene);
    void ballsUpdate();
    ~GUI();
protected:
    graphics_scene  * foreground = new graphics_scene();
    graphics_scene  * balls = new graphics_scene();
    graphics_scene  * background = new graphics_scene();
    Game *game;
};
#endif // GUI_H
