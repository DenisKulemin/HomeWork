#ifndef TROADOBJECTS_H
#define TROADOBJECTS_H
#include <TRoad.h>
#include <TCar.h>
#include <TTrafficLight.h>
#include <vector>
#include <algorithm>
#include <QWidget>

class TRoadObjects : public QWidget
{
    public:
        TRoadObjects(QWidget *parent = 0);
        TRoadObjects(QWidget *parent, TRoad *road0);
        virtual ~TRoadObjects();

        TRoad & getRoad();
        void setRoad(TRoad *road0);

        void addCarToRoad(TCar *car);
        void removeCarFromRoad(TCar *car);
        void addTrafficLightToRoad(TTrafficLight *traffic_light);
        void removeTrafficLightFromRoad(TTrafficLight *traffic_light);
        TTrafficLight* getNearestTrafficLight(TRoad *road, TCar *car);
        void moveCarOnRoad(TCar *car, TTrafficLight *traffic_light);


    protected:
        void paintEvent(QPaintEvent *e);
        void timerEvent(QTimerEvent *);

    private:
        TRoad *road;
        std::vector<TCar *> cars;
        std::vector<TTrafficLight *> trafficLights;
        int timerId;
        static const int DELAY = 100;
};

#endif // TROADOBJECTS_H
