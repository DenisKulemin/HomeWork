#include "TRoadObjects.h"
#include <QPainter>
#include <QTime>
#include <time.h>

TRoadObjects::TRoadObjects(QWidget *parent) : QWidget(parent)
{
    road = nullptr;
    timerId = startTimer(DELAY);
}

TRoadObjects::TRoadObjects(QWidget *parent, TRoad *road0) : QWidget(parent)
{
    road = road0;
    timerId = startTimer(DELAY);
}

TRoadObjects::~TRoadObjects()
{
    std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void TRoadObjects::addCarToRoad(TCar *car)
{
    cars.push_back(car);
}

void TRoadObjects::setRoad(TRoad *road0)
{
    road = road0;
}

TRoad & TRoadObjects::getRoad()
{
    return *road;
}

void TRoadObjects::removeCarFromRoad(TCar *car)
{
    auto it = std::find(cars.begin(), cars.end(), car);
    if (it != cars.end()) {
        cars.erase(it);
    }
    else {
        std::cout << "There isn't such car on the road!" << std::endl;
    }
}

void TRoadObjects::addTrafficLightToRoad(TTrafficLight *traffic_light)
{
    trafficLights.push_back(traffic_light);
}

void TRoadObjects::removeTrafficLightFromRoad(TTrafficLight *traffic_light)
{
    auto it = std::find(trafficLights.begin(), trafficLights.end(), traffic_light);
    if (it != trafficLights.end()) {
        trafficLights.erase(it);
    }
    else {
        std::cout << "There isn't such car on the road!" << std::endl;
    }
}

void TRoadObjects::moveCarOnRoad(TCar *car, TTrafficLight *traffic_light)
{
    char cur_light = traffic_light->getCurrentLight();
    std::cout << cur_light << std::endl;
    // Check if car won't met the traffic light when makes a move
    // Or alreary left traffic light behind.
    // TODO add method to get the next traffic light if them more than one.
    if (car->getX() + car->getV() <= traffic_light->getX() or car->getX() > traffic_light->getX()) {
        car->move_car();
    }
    else if (cur_light == 'g') {
        car->move_car();
    }
    else if (cur_light == 'y') {
        std::cout << "Yellow light - car doesn't move." << std::endl;
    }
    else {
        std::cout << "Red light - car doesn't move." << std::endl;
    }
}

TTrafficLight* TRoadObjects::getNearestTrafficLight(TRoad *road, TCar *car)
{
    TTrafficLight *traffic_light = nullptr;
    float distance = road->getLenght();
    for (auto el : trafficLights) {
        float new_distance = el->getX() - car->getX();
        if (new_distance >=0 and new_distance < distance) {
            traffic_light = el;
            distance = new_distance;
        }
    }
    if (traffic_light != nullptr) return traffic_light;
    else return trafficLights[0];
}

void TRoadObjects::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter qp(this);

    road->show(&qp);
    for (auto el : cars) {
        TTrafficLight *nearest_traffic_light = getNearestTrafficLight(road, el);
        moveCarOnRoad(el, nearest_traffic_light);
        el->show(&qp);
    }
    for (auto el : trafficLights) {
        el->show(&qp);
    }
//
    std::cout << "Now sleep." << clock() << std::endl;
}

void TRoadObjects::timerEvent(QTimerEvent *e) {

    Q_UNUSED(e);
    repaint();
}
