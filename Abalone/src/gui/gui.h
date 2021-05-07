#ifndef GUI_H
#define GUI_H

#include <QGraphicsScene>
#include <QMainWindow>
#include "../abalonecore/game.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <cmath>
#include <QPen>
#include <QPushButton>

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

    /**
     * @brief Updates players balls
     */
    void ballsUpdate();


    void addToCommandAndToBoxes(point<int> pos);

    /**
     * @brief Get's users command.
     * @return User command
     */
    std::string getCommand();

    /**
     * @brief Error to display on GUI
     * @param error Error message to display.
     */
    void commandError(std::string error);

    /**
     * @brief Updates display.
     */
    void updateDisplay();

    /**
     * @brief Updates user command.
     */
    void updateCommand();
    void addMarking();
    void addButtons();

    /**
     * @brief Switches the players turn.
     */
    void switchPlayerTurn();

    /**
     * @brief Checks looser of the game.
     */
    void checkLoser();
    /**
     * @brief End game procedure when game is finished.
     */
    void endGame();
    ~GUI();
protected:
    QWidget *parent=nullptr;
    graphics_scene  * foreground = new graphics_scene();
    graphics_scene  * balls = new graphics_scene();
    graphics_scene  * background = new graphics_scene();
    Game *game;
    std::string firstPos="";
    std::string secondPos="";
    std::string thirdPos="";
    std::string command="";
    std::string error="";
    QString playerTurnDisplayed="Player 1";
    QGraphicsTextItem * pos1Item = new QGraphicsTextItem();
    QGraphicsTextItem * pos2Item = new QGraphicsTextItem();
    QGraphicsTextItem * pos3Item = new QGraphicsTextItem();
    QGraphicsTextItem * errorItem = new QGraphicsTextItem();
    QGraphicsTextItem * playerTurnItem = new QGraphicsTextItem();
    QGraphicsTextItem * errorTurnItem = new QGraphicsTextItem();
    QPushButton *resetBt = nullptr;
    QPushButton *sendBt = nullptr;
    double rad;
    Color colorCurrPlayer=WHITE;
    Color  loser = EMPTY;
private slots:
    void resetCommand();
    void sendCommand();
};
#endif // GUI_H
