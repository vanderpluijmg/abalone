#include "hexacell.h"

#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QBrush>
#include <QPainter>

#include <iostream>
#include <cmath>

#include "point.hpp"
#include "gui.h"

double const HexaCell::zValMax = 10000;//arbitrary

HexaCell::HexaCell( int dx, int dy,double rad, GUI* gui,Qt::GlobalColor color)
    : QGraphicsPolygonItem(nullptr),
      pos(make_point(dx,dy)),
      rad(rad),
      color(color),
      _gui(gui)
{
    this->setAcceptHoverEvents(true);
    zval = zValue();
    static const double piOver6 = atan(1) * 4/6;
    //Paramètres utiles au positionnement et aux dessins

    point<double> final = cartesianForAbalone(pos,rad);

    QPolygonF polygon;
    auto&& corners = orbit(final,6, rad, piOver6);
    for(auto& p : corners)
        polygon << QPointF(p.first, p.second);

    setPolygon(polygon);
}
point<int> HexaCell::getPos(){
    return this->pos;
}


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void HexaCell::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{

    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    QBrush brush;
    brush.setColor(color);
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawPolygon(polygon());
}

void HexaCell::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    //std::cout<<this->pos.first<<"   "<<this->pos.second<<std::endl;
    _gui->addToCommandAndToBoxes(pos);
}

#pragma GCC diagnostic pop

