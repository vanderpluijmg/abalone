#include "ball.h"

#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QBrush>
#include <QPainter>

#include <iostream>
#include <cmath>

#include "point.hpp"

double const Ball::zValMax = 10000;//arbitrary

Ball::Ball( int dx, int dy,double rad,Color color)
    : QGraphicsPolygonItem(nullptr),
      pos(make_point(dx,dy)),
      rad(rad),
      color(color)
{
    this->setAcceptHoverEvents(true);
    zval = zValue();
    static const double piOver6 = atan(1) * 3/6;

    //Paramètres utiles au positionnement et aux dessins
    double radCell = rad;
    double radBall = rad*2/5;

    point<double> final = cartesianForAbalone(pos,radCell);

    QPolygonF polygon;
    auto&& corners = orbit(final,350, radBall, piOver6);
    for(auto& p : corners)
        polygon << QPointF(p.first, p.second);

    setPolygon(polygon);
}
point<int> Ball::getPos(){
    return this->pos;
}


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void Ball::paint(QPainter *painter,
                 const QStyleOptionGraphicsItem *option,
                 QWidget *widget)
{


    QBrush brush;
    if(this->color==BLACK){
        QPen pen(Qt::black, 1);
        painter->setPen(pen);
        brush.setColor(Qt::black);
    }
    if(this->color==WHITE){
        QPen pen(Qt::white, 1);
        painter->setPen(pen);
        brush.setColor(Qt::white);
    }
    brush.setStyle(Qt::SolidPattern);

    painter->setBrush(brush);


    painter->drawPolygon(polygon());
}

#pragma GCC diagnostic pop

