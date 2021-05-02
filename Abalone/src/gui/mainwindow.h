#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void addGameBoardAbalone(Board board, graphics_scene  * scene);
    void addBallsAbalone(Board board, graphics_scene  * scene);
    ~MainWindow();
};
#endif // MAINWINDOW_H
