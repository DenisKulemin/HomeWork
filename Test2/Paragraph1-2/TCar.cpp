#include "TCar.h"

TCar::TCar()
{
    road = nullptr;
    p = 0;
    v = 0;
    x = 0;
}

TCar::TCar (QWidget *parent, TRoad *road0, int p0, float v0 )  : QWidget(parent)
{
    road = road0;
    p = p0;
    v = v0;
    x = 0;
}

TCar::~TCar()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

TRoad & TCar::getRoad()
{
    return *road;
}

void TCar::setRoad(TRoad *road0)
{
    road = road0;
}

float TCar::getX()
{
    return x;
}

void TCar::setX(float x0)
{
    x = x0;
}

float TCar::getV()
{
    return v;
}

void TCar::setV(float v0)
{
    v = v0;
}

int TCar::getP()
{
    return p;
}

void TCar::setP(int p0)
{
    p = p0;
}

void TCar::move_car()
{
    x = x + v;
    if ( x > road->getLenght() ) x = 0;
}

void TCar::show(QPainter *qp)
{
    qp->setBrush(QBrush(QColor(255, 255, 255)));
    qp->setPen(QColor(0, 0, 0));
    qp->drawRect(10 + x, 10 + p * 40, 15, 15);
}
