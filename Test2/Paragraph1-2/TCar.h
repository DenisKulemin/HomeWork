#ifndef TCAR_H
#define TCAR_H
#include <TRoad.h>
#include <QWidget>
#include <QPainter>

class TCar : public QWidget
{
    public:
        // Create TCar() to make easier to create TCar array in main()
        TCar();
        TCar(QWidget *parent, TRoad *road0, int p0, float v0 );
        void move_car();
        virtual ~TCar();
        void show(QPainter *qp);

        float getX();
        void setX(float x0);

        float getV();
        void setV(float v0);

        int getP();
        void setP(int p0);

        TRoad & getRoad();
        void setRoad(TRoad *road0);

    protected:

    private:
        float x, v;
        int p;
        TRoad *road;
};

#endif // TCAR_H
