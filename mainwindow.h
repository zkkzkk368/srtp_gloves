#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sensormonitor.h"
#include "serialportmonitor.h"
#include <QListWidgetItem>
#include <QList>
#include <QFile>
#include <QTextCodec>
#include <QDebug>
#include "ruleitem.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <blthandler.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_actionOpenSensorMonitor_triggered();

    void on_tbAddExpression_clicked();

    void on_pbApplyExpression_clicked();

    void on_tbDeleteExpression_clicked();

    void on_lwExpression_itemDoubleClicked(QListWidgetItem *item);

    void on_lwExpression_itemClicked(QListWidgetItem *item);

    void on_actionOpenBthPortMonitor_triggered();

    void on_subactionsBluetoothConnect_triggered(QAction *act);

    void on_actionBluetoothDisconnect_triggered();

    void on_actionactionBluetoothStatus_triggered();

    void bluetoothHandler();

private:
    Ui::MainWindow *ui;
    SensorMonitor sensorMonitor;    // 传感器监视窗界面
    SerialPortMonitor serialPortMonitor;    // 串口调试窗口
    QList<RuleItem *> ruleItems;    // 规则对象列表
    QFile file;                     // 规则记录文件
    int seletedItemIndex;           // 列表中当前选中项对应的规则对象的索引号
    QSerialPort serial;
};

#endif // MAINWINDOW_H
