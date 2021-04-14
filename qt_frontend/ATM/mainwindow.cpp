#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pengineatm = new engineatm;
    connect(pengineatm,SIGNAL(sendSignalToExeFromEngineRfid()),this,SLOT(SignalFromEngineRfidToExe()),Qt::QueuedConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete pengineatm;
}

void MainWindow::SignalFromEngineRfidToExe()
{
//    ppin = new pin;
    this->hide();
//    ppin->exec();
//    ppin->show();
//    delete ppin;
    //    ppin = nullptr;
}

void MainWindow::on_pushButton_clicked()
{
    pnosto = new nosto;
    pnosto->exec();
    pnosto->show();
    delete pnosto;
    pnosto = nullptr;
}
