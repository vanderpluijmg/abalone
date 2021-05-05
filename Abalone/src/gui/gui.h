#ifndef GUI_H
#define GUI_H

#include <QGraphicsScene>
#include <QMainWindow>
#include "../abalonecore/game.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cmath>
#include <QPen>

#include "ball.h"
#include "point.hpp"
#include "graphics_scene.hpp"
#include <list>


class GUI : public QMainWindow
{
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr,Game*g=nullptr,double rad=50);
    void addGameBoardAbalone(Board board, graphics_scene  * scene,Qt::GlobalColor color);
    void addBallsAbalone(Board board, graphics_scene  * scene);
    void ballsUpdate();
    std::string posToAbaString(point<int> pos);
    void addToCommandAndToBoxes(point<int> pos);
    std::string getCommand();
    void commandError(std::string error);
    void updateDisplay();
    void updateCommand();
    void addMarking();
    void addButtons();
    void setPlayerTurn(Color color);
    ~GUI();
protected:
    graphics_scene  * foreground = new graphics_scene();
    graphics_scene  * balls = new graphics_scene();
    graphics_scene  * background = new graphics_scene();
    Game *game;
    std::string firstPos="";
    std::string secondPos="";
    std::string thirdPos="";
    std::string command="";
    std::string error="";
    QGraphicsTextItem * pos1Item = new QGraphicsTextItem();
    QGraphicsTextItem * pos2Item = new QGraphicsTextItem();
    QGraphicsTextItem * pos3Item = new QGraphicsTextItem();
    QGraphicsTextItem * errorItem = new QGraphicsTextItem();
    double rad;
    Color colorCurrPlayer=WHITE;
private slots:
    void resetCommand();
    void sendCommand();
};
#endif // GUI_H
