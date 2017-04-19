#include "sensormonitor.h"
#include "ui_sensormonitor.h"

SensorMonitor::SensorMonitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SensorMonitor)
{
    ui->setupUi(this);
}

SensorMonitor::~SensorMonitor()
{
    delete ui;
}
