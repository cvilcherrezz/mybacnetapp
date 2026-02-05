#include "backend.h"
#include <QRandomGenerator>

Backend::Backend(QObject *parent)
    : QObject(parent), temperature(20.0)
{
    connect(&timer, &QTimer::timeout, this, &Backend::generateData);
    timer.start(1000); // every second
}

void Backend::generateData()
{
    //Randomly fluctuate temperature by ±0.5 °C
    double delta = (QRandomGenerator::global()->generateDouble() - 0.5);
    temperature += delta;
    emit newTemperature(temperature);
}
