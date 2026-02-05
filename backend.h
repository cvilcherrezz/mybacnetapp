#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QTimer>

class Backend : public QObject
{
    Q_OBJECT

public:
    explicit Backend(QObject *parent = nullptr);

signals:
    void newTemperature(float value);

private slots:
    void generateData();

private:
    QTimer timer;
    float temperature;
};

#endif
