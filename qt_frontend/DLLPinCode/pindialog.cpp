#include "pindialog.h"
#include "ui_pindialog.h"

pindialog::pindialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pindialog)
{
    ui->setupUi(this);
    ui->lineEditPin->setEchoMode(QLineEdit::Password);
//    timerPin = new QTimer(this);
//    connect(timerPin, SIGNAL(timeout()),this,SLOT(timerslotPin()));
}

pindialog::~pindialog()
{
    delete ui;
//    delete timerPin;
}

//void pindialog::startTimerPin()
//{
//    timerPin->start(5000);
//}

void pindialog::on_pushButtonOK_clicked()
{
    int pinnumber = QString (ui->lineEditPin->text()).toInt();
    qDebug() << "dllpin";
    qDebug() << pinnumber;
    emit sendSignalToDllPinInterface(pinnumber);
}

void pindialog::receiveWrongPinFromDLLPinCode()
{
    ui->labelWrongPin->setText("Väärä PIN");
}

void pindialog::receiveClosePinDialog()
{
//    timerPin->stop();
    this->close();
}

//void pindialog::timerslotPin()
//{
//    qDebug() << "kirjaudu ulos pin";
//}

//void pindialog::keyPressEvent(QKeyEvent *eventKey)
//{
//    if(eventKey){
//        timerPin->stop();
//        qDebug() << "timer reset key pin";
//        timerPin->start(5000);
//    }
//}

//void pindialog::mousePressEvent(QMouseEvent *eventMouse)
//{
//    if(eventMouse){
//        timerPin->stop();
//        qDebug() << "timer reset mouse pin";
//        timerPin->start(5000);
//    }
//}
