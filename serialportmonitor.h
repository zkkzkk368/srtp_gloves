#ifndef SERIALPORTMONITOR_H
#define SERIALPORTMONITOR_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "blthandler.h"

namespace Ui {
class SerialPortMonitor;
}

class SerialPortMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit SerialPortMonitor(QWidget *parent = 0);
    ~SerialPortMonitor();

private slots:

    void on_pbBthOpen_clicked();

    void on_pbBthClose_clicked();

    void ReadData();

    void on_pbSend_clicked();

private:
    Ui::SerialPortMonitor *ui;
    QSerialPort serial;
};

#endif // SERIALPORTMONITOR_H
