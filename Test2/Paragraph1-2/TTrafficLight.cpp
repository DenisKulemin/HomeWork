#include "TTrafficLight.h"
#include <QPainter>

TTrafficLight::TTrafficLight(QWidget *parent) : QWidget(parent)
{
    road = nullptr;
    x = 0;
}

TTrafficLight::TTrafficLight(QWidget *parent, TRoad *road0, float x0) : QWidget(parent)
{
    road = road0;
    x = x0;
}

TRoad & TTrafficLight::getRoad()
{
    return *road;
}

void TTrafficLight::setRoad(TRoad *road0)
{
    road = road0;
}

float TTrafficLight::getX()
{
    return x;
}

void TTrafficLight::setX(float x0)
{
    x = x0;
}

TTrafficLight::~TTrafficLight()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

clock_t TTrafficLight::getGreen()
{
    return green;
}

clock_t TTrafficLight::getYellow()
{
    return yellow;
}

clock_t TTrafficLight::getRed()
{
    return red;
}


void TTrafficLight::showCurrentTime()
{
    currentTime = getCurrentTime();
}

clock_t TTrafficLight::getCurrentTime()
{
    // Convert standard return time format to sec
    currentTime = clock() / static_cast<double>(CLOCKS_PER_SEC);
    return currentTime;
}

char TTrafficLight::getCurrentLight()
{
    clock_t currentTime = getCurrentTime();
    clock_t cur_period = green + yellow + red;
    std::cout << currentTime << std::endl;

    if (currentTime % cur_period < green) {
        return 'g';
    }
    else if (currentTime % cur_period < green + yellow) {
        return 'y';
    }
    else {
        return 'r';
    }
}

void TTrafficLight::show(QPainter *qp)
{
    char cur_light = getCurrentLight();
    switch (cur_light) {
    case 'g':
        qp->setBrush(QBrush(QColor(0, 255, 0)));
        break;
    case 'y':
        qp->setBrush(QBrush(QColor(255, 255, 0)));
        break;
    case 'r':
        qp->setBrush(QBrush(QColor(255, 0, 0)));
        break;
    }

    qp->setPen(QColor("ffffff"));

    qp->drawRect(10 + x, 20, 15, 15);
}
