#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include "../abalonecore/game.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void addGameBoardAbalone(Board board, QGraphicsScene  * scene);
    ~MainWindow();
};
#endif // MAINWINDOW_H
