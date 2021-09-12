#ifndef TROAD_H
#define TROAD_H
#include <iostream>
#include <QWidget>
#include <QPainter>

class TRoad : public QWidget
{
    public:
        TRoad(QWidget *parent);
        TRoad(QWidget *parent = 0, float length0 = 100, int width0 = 3);

        float getLenght();
        void setLenght(float length0);

        int getWidth();
        void setWigth(int width0);

        virtual ~TRoad();
        void show(QPainter *qp);

    protected:

    private:
        float length;
        int width;
};

#endif // TROAD_H
