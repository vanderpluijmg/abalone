#ifndef HEXACELL_H
#define HEXACELL_H

#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <string>
#include <QPointF>
#include "point.hpp"


class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QGraphicsSceneHoverEvent;
class QGraphicsSceneMouseEvent;
class QGraphicsSceneWheelEvent;

class HexaCell  : public QGraphicsPolygonItem
{
    static const double zValMax; //z-val of selected items
    double zval; //z-val at instanciation

    protected:
        point<int> pos;//hexagon radius, coordinate (x,y) of center
        bool mouseover, selected, moved;//mouse interaction booleans

    public:
        HexaCell(int dx = 0,
                 int dy = 0);

        void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

        inline QPointF coord(double x, double y) const;

        inline void setLocation(double x, double y);
protected: point<int> getPos();

    protected:
        void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
        void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
        void mousePressEvent(QGraphicsSceneMouseEvent * event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
        void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
        void wheelEvent(QGraphicsSceneWheelEvent * event);
};

#endif // HEXACELL_H
