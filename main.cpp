#include <QApplication>
#include <QWidget>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHeaderView>
#include "backend.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Mini YABE – Qt + C++");

    QTableWidget *table = new QTableWidget(1, 2);
    table->setHorizontalHeaderLabels({"Sensor", "Value"});
    table->horizontalHeader()->setStretchLastSection(true);

    table->setItem(0, 0, new QTableWidgetItem("Temperature Sensor"));
    table->setItem(0, 1, new QTableWidgetItem("20.0 °C"));

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(table);
    window.setLayout(layout);

    Backend backend;

    QObject::connect(&backend, &Backend::newTemperature,
                     [&](float value) {
        table->item(0, 1)->setText(QString::number(value, 'f', 1) + " °C");
    });

    window.resize(400, 200);
    window.show();

    return app.exec();
}
