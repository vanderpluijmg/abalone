#include "gui.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <cmath>
#include <QPen>
#include <QPushButton>
#include <iostream>

#include "hexacell.h"
#include "ball.h"
#include "point.hpp"

/**
 * @brief Graphical User Interface.
 */
GUI::GUI(QWidget *parent,Game* game,double rad)
    : QMainWindow(parent),    game(game),rad(rad)
{
    addGameBoardAbalone(game->getBoard(),background,Qt::gray);
    addBallsAbalone(game->getBoard(),balls);
    addGameBoardAbalone(game->getBoard(),foreground,Qt::transparent);
    //fonts for displaying
    QFont  fPlayers = QFont();//font for player badges
    fPlayers.setPointSize(rad/5);
    QFont  fMarking = QFont();//font for marking
    fMarking.setPointSize(rad/3);
    //encapsulation des différentes scénes
    QGraphicsView * view = new QGraphicsView(foreground);
    foreground->set_background_scene(balls);
    balls->set_background_scene(background);

    //ajout des démarquations
    addMarking();
    //ajout des boutons
    addButtons();

    updateDisplay();
    //paramètrage de la scene
    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::TextAntialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);

    view->update();

    this->setCentralWidget(view);
}

GUI::~GUI()
{
}

void GUI::addGameBoardAbalone(Board board, graphics_scene  * scene,Qt::GlobalColor color){
    for (int i = 0; i < 9; i++) {
        for (int j = 0;j<9 ; j++) {
            if(board.isOnBoard(Position(j,i))){
                scene->addItem(new HexaCell(j, i,rad,this,color));

            }
        }
    }
}

void GUI::addBallsAbalone(Board board, graphics_scene  * scene){
    for (int i = 0; i < 9; i++) {
        for (int j = 0;j<9 ; j++) {
            if(board.isOnBoard(Position(j,i))){
                Color color = board.getColor(Position(j,i));
                if (color == BLACK)scene->addItem(new Ball( j, i,rad,color));
                if (color == WHITE)scene->addItem(new Ball( j, i,rad,color));
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
    addBallsAbalone(game->getBoard(),balls);
}

std::string GUI::posToAbaString(point<int> pos){
    std::string posStr = "";
    char row = pos.second;
    int col = pos.first + 1;
    switch (row){
    case 0: {posStr+="I";posStr+=std::to_string(col);return posStr;};
    case 1: {posStr+="H";posStr+=std::to_string(col);return posStr;};
    case 2: {posStr+="G";posStr+=std::to_string(col);return posStr;};
    case 3: {posStr+="F";posStr+=std::to_string(col);return posStr;};
    case 4: {posStr+="E";posStr+=std::to_string(col);return posStr;};
    case 5: {posStr+="D";posStr+=std::to_string(col);return posStr;};
    case 6: {posStr+="C";posStr+=std::to_string(col);return posStr;};
    case 7: {posStr+="B";posStr+=std::to_string(col);return posStr;};
    case 8: {posStr+="A";posStr+=std::to_string(col);return posStr;};
    }
    return "";
}

void GUI::addToCommandAndToBoxes(point<int> pos){
    if(this->firstPos.empty()){firstPos=this->posToAbaString(pos);command+=firstPos;}
    else if(this->secondPos.empty()){secondPos=this->posToAbaString(pos);command+=secondPos;}
    else if(this->thirdPos.empty()){thirdPos=this->posToAbaString(pos);command+=thirdPos;}
    else {resetCommand();firstPos=this->posToAbaString(pos);command=firstPos;}
    updateDisplay();
    update();

}

void GUI::resetCommand(){
    command.clear();
    firstPos="";
    secondPos="";
    thirdPos="";
    updateDisplay();
}

std::string GUI::getCommand(){
    return command;
}

void GUI::sendCommand(){
    bool moveApproved = true;
    if(command!=""||command.length()>3){
        moveApproved=game->applyMove(AbaPro::getCommand(command),WHITE);
        if(!moveApproved)
            commandError("wrong move");
    }
    resetCommand();
    updateDisplay();
}
void GUI::commandError(std::string error){
    this->error=error;
    update();
}

void GUI::updateDisplay(){
    ballsUpdate();
    pos1Item->setPlainText(QString::fromStdString(firstPos));
    pos2Item->setPlainText(QString::fromStdString(secondPos));
    pos3Item->setPlainText(QString::fromStdString(thirdPos));
    resize(rad*22.5, rad*18-1);
    resize(rad*22.5, rad*18);
    update();
}

void GUI::addMarking(){
    QFont  font = QFont();//font for marking
    font.setPointSize(rad/3);
    //Texte pour player 1 et player 2
    QString Player1Text = "Player 1";
    QGraphicsTextItem * Player1Graph = new QGraphicsTextItem();
    Player1Graph->setPlainText(Player1Text);
    Player1Graph->boundingRect();
    QString Player2Text = "Player 2";
    QGraphicsTextItem * Player2Graph = new QGraphicsTextItem();
    Player2Graph->setPlainText(Player2Text);
    Player2Graph->boundingRect();
    Player1Graph->setPos(-4.2*rad, rad*-8);
    Player2Graph->setPos(-4.2*rad, rad*8);
    Player1Graph->setFont(font);
    Player2Graph->setFont(font);
    background->addItem(Player1Graph);
    background->addItem(Player2Graph);
    //Ajout des démarquations
    for(int i = 0, j =4;i<9;i++){
        if(j>=0)j--;
        point<double> pos = make_point(j,i);
        point<double> final = cartesianForAbalone(pos,rad);
        final = make_point((double)final.first,final.second-rad/2);
        char a = 73-i;
        QString text = QString(QChar::fromLatin1(a));
        QGraphicsTextItem * item = new QGraphicsTextItem();
        item->setPlainText(text);
        item->setPos(QPoint(final.first,final.second));
        item->setFont(font);
        background->addItem(item);
    }
    for(int i = 0, j =9;i<9;i++){
        if(i>=5)j--;
        point<double> pos = make_point(i,j);
        point<double> final = cartesianForAbalone(pos,rad);
        QString text = QString::number(i+1);
        QGraphicsTextItem * item = new QGraphicsTextItem();
        item->setPlainText(text);
        item->setPos(QPoint(final.first-rad*1/4,final.second-rad/2));
        item->setFont(font);
        background->addItem(item);
    }
    //Player command visually displayed
    QFont  fontMoves = QFont();//font for marking
    fontMoves.setPointSize(rad/3);
    //Texte pour player 1 et player 2
    pos1Item->setPlainText(QString(""));
    pos1Item->boundingRect();
    pos2Item->setPlainText(QString(""));
    pos2Item->boundingRect();
    pos3Item->setPlainText(QString(""));
    pos3Item->boundingRect();
    pos1Item->setPos(7*rad, rad*-4);
    pos2Item->setPos(7*rad, rad*-2.5);
    pos3Item->setPos(7*rad, rad*-1);
    pos1Item->setFont(fontMoves);
    pos2Item->setFont(fontMoves);
    pos3Item->setFont(fontMoves);
    background->addItem(pos1Item);
    background->addItem(pos2Item);
    background->addItem(pos3Item);
    updateDisplay();
}

void GUI::addButtons(){
    //Bouton remise à 0 de la commande
    QPushButton *resetBt = new QPushButton();
    resetBt->setText("remise à 0");
    resetBt->setGeometry(6*rad,rad,3*rad,rad);
    connect(resetBt,SIGNAL(clicked()),SLOT(resetCommand()));

    //couleur reset
    QPalette pal = resetBt->palette();
    pal.setColor(QPalette::Button, QColor(Qt::gray));
    resetBt->setAutoFillBackground(true);
    resetBt->setPalette(pal);
    resetBt->update();

    //Bouton envoi de la commande
    QPushButton *sendBt = new QPushButton();
    sendBt->setText("Envoi de la commande");
    sendBt->setGeometry(6*rad,2.5*rad,3*rad,rad);
    connect(sendBt,SIGNAL(clicked()),SLOT(sendCommand()));
    //couleur send
    QPalette pal1 = sendBt->palette();
    pal1.setColor(QPalette::Button, QColor(Qt::blue));
    sendBt->setAutoFillBackground(true);
    sendBt->setPalette(pal);
    sendBt->update();

    foreground->addWidget(resetBt);
    foreground->addWidget(sendBt);
    updateDisplay();
}
void GUI::setPlayerTurn(Color color){
    colorCurrPlayer=color;
}





