#ifndef SENSORMONITOR_H
#define SENSORMONITOR_H

#include <QWidget>

namespace Ui {
class SensorMonitor;
}

class SensorMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit SensorMonitor(QWidget *parent = 0);
    ~SensorMonitor();

private:
    Ui::SensorMonitor *ui;
};

#endif // SENSORMONITOR_H
