#ifndef BALL_H
#define BALL_H

#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <string>
#include <QPointF>
#include "../abalonecore/color.hpp"
#include "point.hpp"


class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QGraphicsSceneHoverEvent;
class QGraphicsSceneMouseEvent;
class QGraphicsSceneWheelEvent;

class Ball  : public QGraphicsPolygonItem
{
    static const double zValMax; //z-val of selected items
    double zval; //z-val at instanciation

protected:
    point<int> pos;//hexagon radius, coordinate (x,y) of center
    double rad;//size of the Ball
    Color color;//Color to paint the ball in
public:
    Ball(int dx = 0,
         int dy = 0,
         double rad=50,
         Color color=BLACK);

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    point<int> getPos();
};

#endif // BALL_H
