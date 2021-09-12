#include "TRoad.h"
#include <QPainter>

TRoad::TRoad(QWidget *parent) : QWidget(parent)
{
    length = 0;
    width = 0;
}

TRoad::TRoad(QWidget *parent, float lenght0, int width0) : QWidget(parent)
{
    if (lenght0 > 0) {
        length = lenght0;
    }
    else {
        std::cout << "Wrong length (<= 0)" << std::endl;
    }
    if (width0 > 0) {
        width = width0;
    }
    else {
        std::cout << "Wrong width (<= 0)" << std::endl;
    }
}

TRoad::~TRoad()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

float TRoad::getLenght()
{
    return length;
}

void TRoad::setLenght(float length0)
{
    length = length0;
}

int TRoad::getWidth()
{
    return width;
}

void TRoad::setWigth(int width0)
{
    width = width0;
}

void TRoad::show(QPainter *qp)
{
    QPen penSolidLine(Qt::black, 2, Qt::SolidLine);
    qp->setPen(penSolidLine);

    // Draw road border
    qp->drawLine(20, 40, length + 20, 40);
    if (width > 1) {
        QPen penDashLine(Qt::black, 2, Qt::DashLine);
        qp->setPen(penDashLine);
        for (int i = 1; i < width; i++) {
            // Draw border between road lanes
            qp->drawLine(20, 40 + i * 40, length + 20, 40 + i * 40);
        }
        qp->setPen(penSolidLine);
    }
    qp->drawLine(20, 40 + width * 40, length + 20, 40 + width * 40);
}
