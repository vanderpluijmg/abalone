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
        bool mouseover, selected, moved;//mouse interaction booleans
        Color color;

    public:
        Ball(int dx = 0,
                 int dy = 0,Color color=BLACK);

        void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

        inline QPointF coord(double x, double y) const;

        inline void setLocation(double x, double y);
protected: double getDx();

    protected:
        void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
        void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
        void mousePressEvent(QGraphicsSceneMouseEvent * event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
        void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
        void wheelEvent(QGraphicsSceneWheelEvent * event);
};

#endif // BALL_H
