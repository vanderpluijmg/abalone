#include "mainwindow.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <cmath>

#include "hexacell.h"
#include "point.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QGraphicsScene  * scene = new QGraphicsScene();

    double rad = 100;
    double w = sqrt(3) / 2 * rad;

    scene->addItem(new HexaCell(rad, 0, 0, nullptr));

    auto&& centers = orbit({0,0}, 6., 2 * w, 0.);

std::cout<<centers.at(0).first<<"    "<<centers.at(0).second<<std::endl;
std::cout<<centers.at(1).first<<"    "<<centers.at(1).second<<std::endl;
std::cout<<centers.at(2).first<<"    "<<centers.at(2).second<<std::endl;
std::cout<<centers.at(3).first<<"    "<<centers.at(3).second<<std::endl;
std::cout<<centers.at(4).first<<"    "<<centers.at(4).second<<std::endl;
std::cout<<centers.at(5).first<<"    "<<centers.at(5).second<<std::endl;

    for(auto& p : centers)
        scene->addItem((new HexaCell(rad, p.first, p.second, nullptr)));

    QGraphicsView * view = new QGraphicsView(scene);

    view->setRenderHint(QPainter::Antialiasing);
    view->setRenderHint(QPainter::TextAntialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);

    view->update();

    resize(1000, 800);

    this->setCentralWidget(view);
}

MainWindow::~MainWindow()
{

}
