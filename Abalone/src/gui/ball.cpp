#include "ball.h"

#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QBrush>
#include <QPainter>

#include <iostream>
#include <cmath>

#include "point.hpp"

double const Ball::zValMax = 10000;//arbitrary

Ball::Ball( int dx, int dy,Color color)
    : QGraphicsPolygonItem(nullptr),
      pos(make_point(dx,dy)),
      mouseover(false), selected(false), moved(false),
      color(color)
{
    this->setAcceptHoverEvents(true);
    zval = zValue();
    static const double piOver6 = atan(1) * 4/6;

    //Paramètres utiles au positionnement et aux dessins
    double radCell = 50;
    double radBall = 20;

    point<double> final = cartesianForAbalone(pos,radCell);

    QPolygonF polygon;
    auto&& corners = orbit(final,100, radBall, piOver6);
    for(auto& p : corners)
        polygon << QPointF(p.first, p.second);

    setPolygon(polygon);
}
double Ball::getDx(){
    return this->pos.first;
}


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void Ball::paint(QPainter *painter,
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
        if(this->color==BLACK)brush.setColor(Qt::black);
        if(this->color==WHITE)brush.setColor(Qt::white);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }

    painter->drawPolygon(polygon());
}

void Ball::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    mouseover = true;
    update();
}

void Ball::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    mouseover = false;
    update();
}

void Ball::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    moved = false;
    selected = !selected; //I'd like to put this in "released"
    std::cout<<pos.first<<"   "<<pos.second<<std::endl;
    update();

    //relaunches the event in order to allow dragging
    QGraphicsItem::mousePressEvent(event);
}

void Ball::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //why isn't this ever fired ?
}

void Ball::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    moved = true;
}

void Ball::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    //write stuff here
    //rad +/-= 10 ?

    QGraphicsItem::wheelEvent(event);
}
#pragma GCC diagnostic pop

