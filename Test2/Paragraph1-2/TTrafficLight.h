#ifndef TTRAFFICLIGHT_H
#define TTRAFFICLIGHT_H
#include <TRoad.h>
#include <time.h>
#include <QWidget>
#include <QPainter>

class TTrafficLight : public QWidget
{
    public:
        TTrafficLight(QWidget *parent);
        TTrafficLight(QWidget *parent, TRoad *road0, float x = 0.0);
        virtual ~TTrafficLight();
        // time in sec

        TRoad & getRoad();
        void setRoad(TRoad *road0);
        float getX();
        void setX(float x0);
        clock_t getGreen();
        void setGreen(clock_t green0);
        clock_t getYellow();
        void setYellow(clock_t yellow0);
        clock_t getRed();
        void setRed(clock_t red0);
        clock_t getCurrentTime();
        void showCurrentTime();
        char getCurrentLight();
        void show(QPainter *qp);

    protected:

    private:
        TRoad *road;
        float x;
        clock_t currentTime;
        clock_t green = 5;
        clock_t yellow = 1;
        clock_t red = 5;
};

#endif // TTRAFFICLIGHT_H
