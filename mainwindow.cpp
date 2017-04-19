#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    file("rules.conf"),
    seletedItemIndex(-1)
{
    ui->setupUi(this);
    // 设置编码为UTF-8
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    // 以读写方式打开文件
//    QFile file("rules.conf");
    if(!file.open(QIODevice::ReadWrite | QIODevice::Text)){
        qDebug() << "Can't open" << endl;
    }
    // 初始化，从文件中逐行读出所有规则
    while(!file.atEnd()){
        // 读取一行规则
        QByteArray line = file.readLine();
        QString strLine(line);
        qDebug() << "<line> " << strLine << endl;
        // 分割字段提取出规则名称、表达式、动作类型
        QStringList strLineSpl = strLine.split(":");
        if(strLineSpl.size() != 3){
            qDebug() << "Something wroing happend in data format" << endl;
        }
        ruleItems << new RuleItem(strLineSpl[0], strLineSpl[1], strLineSpl[2]);
    }
    // <调试>打印各项规则的分割结果
    qDebug() << "<ruleItems>";
    for(int i = 0; i < ruleItems.size(); ++i){
        qDebug() << ruleItems[i]->getName()   << " "
                 << ruleItems[i]->getExp()    << " "
                 << ruleItems[i]->getAction() << " ";
    }
    qDebug() << "</ruleItems>";
    // 将各项规则添加到列表控件中
    for(int i =0; i < ruleItems.size(); ++i){
        ui->lwExpression->addItem( ruleItems[i]->getName() );
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 点击菜单栏中 传感器-状态监视窗 后 打开sensormonitor的窗口
void MainWindow::on_actionOpenSensorMonitor_triggered()
{
    sensorMonitor.show();
}

// 点击列表上方的加号后添加新项<New item>
void MainWindow::on_tbAddExpression_clicked()
{
    ui->lwExpression->addItem("<New item>");
}

// 点击列表上方的减号后删除选中的那一项
void MainWindow::on_tbDeleteExpression_clicked()
{
    QList<QListWidgetItem *> pItems = ui->lwExpression->selectedItems();
    if( !pItems.isEmpty() ){    // 是否有选中项
        QListWidgetItem *pItem = pItems[0];
        ui->lwExpression->removeItemWidget( pItem );
        delete pItem;   // 必须delete掉才能完成删除操作
    }
}

// 点击规则表达式右边的“应用”之后为列表中选中项更新规则表达式
void MainWindow::on_pbApplyExpression_clicked()
{

}

// 列表已经设置editTrigle为doubleClicked，双击可以触发编辑状态
// 双击后将选中项设置为“可编辑”，确保编辑状态能够触发
void MainWindow::on_lwExpression_itemDoubleClicked(QListWidgetItem *item)
{
    item->setFlags( item->flags() | Qt::ItemIsEditable );
}

// 列表中某项被点击选中时，更新表达式输入框和动作输入框中的内容
void MainWindow::on_lwExpression_itemClicked(QListWidgetItem *item)
{
    // 遍历规则项，查找对应的规则对象并将表达式、动作填写入输入框
    for(int i = 0; i < ruleItems.size(); ++i){
        if(item->text() == ruleItems[i]->getName()){
            // 记录选中的规则对象
            seletedItemIndex = i;
            // 更新两输入框的内容
            ui->leExpression->setText( ruleItems[i]->getExp() );
            ui->leAction->setText( ruleItems[i]->getAction() );
            break;
        }
    }
}

// 点击蓝牙 - 调试窗口
// 打开拉那样调试窗口serialPortMonitor
void MainWindow::on_actionOpenBthPortMonitor_triggered()
{
    serialPortMonitor.show();
}

// 点击蓝牙 - 连接
// 连接蓝牙
void MainWindow::on_actionBluetoothConnect_triggered()
{

}
