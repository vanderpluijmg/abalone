#ifndef HEXACELL_H
#define HEXACELL_H

#include <QGraphicsPolygonItem>
#include <QPolygonF>
#include <string>
#include <QPointF>
#include "point.hpp"
#include "gui.h"


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
    double rad; //size of hexagn
    Qt::GlobalColor color; //color to paint hexgon
    GUI *_gui=nullptr; //where it appears

public:
    HexaCell(int dx = 0,
             int dy = 0,
             double rad=50,
             GUI* _gui=nullptr,
             Qt::GlobalColor color = Qt::black);

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    inline QPointF coord(double x, double y) const;

    inline void setLocation(double x, double y);
    point<int> getPos();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // HEXACELL_H
