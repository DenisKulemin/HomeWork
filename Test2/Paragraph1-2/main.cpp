
#include <iostream>
#include <TRoadObjects.h>
#include <conio.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TRoadObjects road_objects;
    road_objects.resize(700, 700);
    road_objects.setWindowTitle("Road's objects");
    road_objects.show();

    TRoad road(road_objects.parentWidget(), 600, 3);
    road_objects.setRoad( &road );

    TTrafficLight traffic_light (road_objects.parentWidget(), &road, 300);
    road_objects.addTrafficLightToRoad(&traffic_light);
    const int N = 3;
    TCar cars[N];
    int i;
    for ( i = 0; i < N; i ++ ) {
        cars[i].setParent(road_objects.parentWidget());
        cars[i].setRoad(&road);
        cars[i].setP(i + 1);
        cars[i].setV( 2.0*(i + 1) );
        road_objects.addCarToRoad(&cars[i]);
    }

    return a.exec();
}
