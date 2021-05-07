#include "gui.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <cmath>
#include <QPen>
#include <QPushButton>
#include <iostream>
#include <QMessageBox>
#include "../abalonecore/abapro.h"
#include "hexacell.h"
#include "ball.h"
#include "point.hpp"

/**
 * @brief Graphical User Interface.
 */
GUI::GUI(QWidget *parent,Game* game,double rad)
    : QMainWindow(parent),
      parent(parent),
      game(game),rad(rad)
{
    //ajout des démarquations
    addMarking();
    //ajout des boutons
    addButtons();
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
    for (int i = 0; i < 9; i++)
        for (int j = 0;j<9 ; j++)
            if(board.isOnBoard(Position(j,i))){
                scene->addItem(new HexaCell(j, i,rad,this,color));
            }
}

void GUI::addBallsAbalone(Board board, graphics_scene  * scene){
    for (int i = 0; i < 9; i++)
        for (int j = 0;j<9 ; j++)
            if(board.isOnBoard(Position(j,i))){
                Color color = board.getColor(Position(j,i));
                if (color == BLACK)scene->addItem(new Ball( j, i,rad,color));
                if (color == WHITE)scene->addItem(new Ball( j, i,rad,color));
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

void GUI::addToCommandAndToBoxes(point<int> pos){
    if(error!="")error="";
    if(this->firstPos.empty()){firstPos=AbaPro::posToAbaString(pos);command+=firstPos;}
    else if(this->secondPos.empty()){secondPos=AbaPro::posToAbaString(pos);command+=secondPos;}
    else if(this->thirdPos.empty()){thirdPos=AbaPro::posToAbaString(pos);command+=thirdPos;}
    else {resetCommand();firstPos=AbaPro::posToAbaString(pos);command=firstPos;}
    updateDisplay();
    update();

}

void GUI::resetCommand(){
    command.clear();
    firstPos="";
    secondPos="";
    thirdPos="";
    error="";
    updateDisplay();
}

std::string GUI::getCommand(){
    return command;
}

void GUI::sendCommand(){
    bool moveApproved = true;
    if(command!="" && secondPos!=""){
        MoveUtils a = AbaPro::getCommand(firstPos+secondPos+thirdPos);
        if (a.dir.getDeltaX() == 0 && a.dir.getDeltaY() == 0)
            moveApproved = false;
        else moveApproved=game->applyMove(a,colorCurrPlayer);
        if(!moveApproved){
            resetCommand();
            commandError("Wrong movement");
        }
        else {
            switchPlayerTurn();
            resetCommand();
        }
    }
    checkLoser();
    updateDisplay();
}
void GUI::commandError(std::string error){
    resetCommand();
    this->error=error;
    errorTurnItem->setPlainText(QString::fromStdString(error));
    update();
}

void GUI::updateDisplay(){
    ballsUpdate();
    pos1Item->setPlainText(QString::fromStdString(firstPos));
    pos2Item->setPlainText(QString::fromStdString(secondPos));
    pos3Item->setPlainText(QString::fromStdString(thirdPos));
    playerTurnItem->setPlainText(playerTurnDisplayed+" has to play!");
    errorTurnItem->setPlainText(QString::fromStdString(error));
    resize(rad*22.5, rad*18-1);
    resize(rad*22.5, rad*18);
    update();
}

void GUI::addMarking(){
    QFont  font = QFont();//font for marking
    font.setPointSize(rad/3);
    //Texte pour player 1 et player 2
    QString player1Text = "Player 1";
    QGraphicsTextItem * player1Graph = new QGraphicsTextItem();
    player1Graph->setPlainText(player1Text);
    player1Graph->boundingRect();
    QString player2Text = "Player 2";
    QGraphicsTextItem * player2Graph = new QGraphicsTextItem();
    player2Graph->setPlainText(player2Text);
    player2Graph->boundingRect();
    player1Graph->setPos(-4.2*rad, rad*-8);
    player2Graph->setPos(-4.2*rad, rad*8);
    player1Graph->setFont(font);
    player2Graph->setFont(font);
    background->addItem(player1Graph);
    background->addItem(player2Graph);
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
    pos1Item->setPos(6.1*rad, rad*-1);
    pos2Item->setPos(7.1*rad, rad*-1);
    pos3Item->setPos(8.1*rad, rad*-1);
    pos1Item->setFont(fontMoves);
    pos2Item->setFont(fontMoves);
    pos3Item->setFont(fontMoves);
    background->addItem(pos1Item);
    background->addItem(pos2Item);
    background->addItem(pos3Item);
    //Player turn display
    playerTurnItem->setPlainText(playerTurnDisplayed+" has to play!");
    playerTurnItem->boundingRect();
    playerTurnItem->setPos(5.6*rad, rad*-2);
    playerTurnItem->setFont(fontMoves);
    background->addItem(playerTurnItem);

    //error display
    errorTurnItem->setPlainText("");
    errorTurnItem->boundingRect();
    errorTurnItem->setPos(5.6*rad, rad*-1);
    errorTurnItem->setFont(fontMoves);
    background->addItem(errorTurnItem);
}

void GUI::addButtons(){
    resetBt = new QPushButton();
    sendBt = new QPushButton();
    //Bouton remise à 0 de la commande
    resetBt->setText("Reset command");
    resetBt->setGeometry(6*rad,rad,3*rad,rad);
    connect(resetBt,SIGNAL(clicked()),SLOT(resetCommand()));

    //couleur reset
    QPalette pal = resetBt->palette();
    pal.setColor(QPalette::Button, QColor(Qt::gray));
    resetBt->setAutoFillBackground(true);
    resetBt->setPalette(pal);
    resetBt->update();

    //Bouton envoi de la commande
    sendBt->setText("Send command");
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
}

void GUI::switchPlayerTurn(){
    if(colorCurrPlayer==BLACK){
        colorCurrPlayer=WHITE;
        playerTurnDisplayed="Player 1";
    } else {
        colorCurrPlayer=BLACK;
        playerTurnDisplayed="Player 2";
    }
}
void GUI::checkLoser(){
    if(game->whoLost()!=EMPTY){
        loser=game->whoLost();
        update();
        endGame();
    }
}

void GUI::endGame(){
    resetCommand();
    QMessageBox::information(parent,("Game is over! "),  loser==BLACK?("Player 1 has won the game, well played!"):("Player 2 has won the game, well played!"));
    exit(0);
}





