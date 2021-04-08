#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptestengine = new engineatm;
    connect(ptestengine,SIGNAL(sendSignalToExeFromEngineRfid()),this,SLOT(SignalFromEngineRfidToExe()),Qt::QueuedConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptestengine;
}

void MainWindow::SignalFromEngineRfidToExe()
{
    ppin = new pin;
    ppin->exec();
    ppin->show();
    delete ppin;
    ppin = nullptr;
}

