#include "serialportmonitor.h"
#include "ui_serialportmonitor.h"

SerialPortMonitor::SerialPortMonitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SerialPortMonitor)
{
    ui->setupUi(this);

    // 查找所有可用的端口并显示到下拉菜单cbBthPort中
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        ui->cbBthPort->addItem(info.portName());
    }
}

SerialPortMonitor::~SerialPortMonitor()
{
    delete ui;
}


// 点击“打开”按钮
void SerialPortMonitor::on_pbBthOpen_clicked()
{
    // 遍历可用端口，找到下拉菜单中选中的端口
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if(info.portName() == ui->cbBthPort->currentText()){
            serial.setPort(info);
            break;
        }
    }
    // 打开端口
    if( serial.open(QIODevice::ReadWrite) ){
        // 失能“打开”按钮和选择端口的下拉菜单，使能“关闭”按钮和“发送按钮”
        ui->pbBthClose->setEnabled(true);
        ui->pbBthOpen->setEnabled(false);
        ui->pbSend->setEnabled(true);
        ui->cbBthPort->setEnabled(false);
        // 打印信息
        ui->tbRecvSend->append(tr("Port open success"));
        // 设置串口通讯：波特率9600,8位数据，无校验，1位停止，无流控
        serial.setBaudRate(QSerialPort::Baud9600);
        serial.setDataBits(QSerialPort::Data8);
        serial.setParity(QSerialPort::NoParity);
        serial.setStopBits(QSerialPort::OneStop);
        serial.setFlowControl(QSerialPort::NoFlowControl);
        // 连接信号（当串口读取到数据时，将数据打印出来）
        QObject::connect(&serial, &QSerialPort::readyRead, this, &SerialPortMonitor::ReadData);
    }else{  // 打开端口失败，打印失败信息
        ui->tbRecvSend->append(tr("Port open fail"));
    }
}


// 点击“关闭”按钮
void SerialPortMonitor::on_pbBthClose_clicked()
{
    // 关闭端口
    serial.close();
    // 使能“打开”按钮和选择端口的下拉菜单，失能“关闭”按钮和“发送按钮”
    ui->pbBthClose->setEnabled(false);
    ui->pbBthOpen->setEnabled(true);
    ui->pbSend->setEnabled(false);
    ui->cbBthPort->setEnabled(true);
}

// 串口读取函数（与QSerialPort::readyRead信号相连接）
// 从缓冲区中读取数据，如果有数据则打印出来
void SerialPortMonitor::ReadData(){
    QByteArray buf;
    int x, y;
    buf = serial.readAll();
    if(!buf.isEmpty()){
        ui->tbRecvSend->append(tr(buf));

        // test！
        if(buf == "t1")
            BltHandler::click();
        else if(buf == "t2")
            BltHandler::doubleClick();
        else if (buf == "t3")
            BltHandler::closeWindow();
        else if (buf == "t4")
            BltHandler::gotoDesktop();
        else if (buf == "t5"){
            BltHandler::getCursorPos(x, y);
            BltHandler::moveTo(x+100, y+100);
        }else if (buf == "t6")
            BltHandler::pressDownKey();
        else if (buf == "t7")
            BltHandler::pressLeftKey();
        else if (buf == "t8")
            BltHandler::pressRightKey();
        else if (buf == "t9")
            BltHandler::pressUpKey();
        else if (buf == "ta")
            BltHandler::pressPageDownKey();
        else if (buf == "tb")
            BltHandler::pressPageUpKey();
    }
    buf.clear();
}


// 点击“发送”按钮
void SerialPortMonitor::on_pbSend_clicked()
{
    QString str = ui->leSendContext->text();
    serial.write(str.toLatin1()); // Latin1为ISO-8859-1编码的别称
    ui->tbRecvSend->append(str);
}
