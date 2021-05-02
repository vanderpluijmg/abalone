#include "hexacell.h"

#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QBrush>
#include <QPainter>

#include <iostream>
#include <cmath>

#include "point.hpp"

double const HexaCell::zValMax = 10000;//arbitrary

HexaCell::HexaCell( int dx, int dy)
    : QGraphicsPolygonItem(nullptr),
      pos(make_point(dx,dy)),
      mouseover(false), selected(false), moved(false)
{this->setAcceptHoverEvents(true);
    zval = zValue();
    static const double piOver6 = atan(1) * 4/6;
    //Paramètres utiles au positionnement et aux dessins
    double rad = 50;

    point<double> final = cartesianForAbalone(pos,rad);



    //    //Transformation vers position cartésiennes compréhensibles à partir des positions du plateau de jeu venant de la classe Board
    //    double horizontalSpace = sqrt(3)*rad;// space taken horizontally by a hexagon = the space between centers of two adjacent hexagons (same line)
    //    double verticalSpace = -1.5*rad;// space taken between two lines in terms of centers of hexagons
    //    double horizontalPos = dx;//Position compared to the first on the left of the line
    //    double horizontalShift =(-8+((double)dy/2))*horizontalSpace;// position of the one most on the leftcompared to center of gameboard
    //    double verticalShift = (4-dy)*verticalSpace;// position of line compared to center of gameboard
    //    double finalX = horizontalShift+horizontalSpace*horizontalPos;
    //    double finalY = verticalShift;

    QPolygonF polygon;
    auto&& corners = orbit(final,6, rad, piOver6);
    for(auto& p : corners)
        polygon << QPointF(p.first, p.second);

    setPolygon(polygon);
}
double HexaCell::getDx(){
    return this->pos.first;
}


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void HexaCell::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    if(selected)
    {
        QPen pen(Qt::blue, 5);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::yellow);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }
    else if(mouseover)
    {
        QPen pen(Qt::blue, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::green);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }
    else
    {
        QPen pen(Qt::blue, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::cyan);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }

    painter->drawPolygon(polygon());
}

void HexaCell::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    mouseover = true;
    update();
}

void HexaCell::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    mouseover = false;
    update();
}

void HexaCell::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    moved = false;
    selected = !selected; //I'd like to put this in "released"
    std::cout<<pos.first<<"   "<<pos.second<<std::endl;
    update();

    //relaunches the event in order to allow dragging
    QGraphicsItem::mousePressEvent(event);
}

void HexaCell::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //why isn't this ever fired ?
}

void HexaCell::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    moved = true;
}

void HexaCell::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    //write stuff here
    //rad +/-= 10 ?

    QGraphicsItem::wheelEvent(event);
}
#pragma GCC diagnostic pop

