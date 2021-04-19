#include "pindialog.h"
#include "ui_pindialog.h"

pindialog::pindialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pindialog)
{
    ui->setupUi(this);
    ui->lineEditPin->setEchoMode(QLineEdit::Password);
}

pindialog::~pindialog()
{
    delete ui;
}

void pindialog::on_pushButtonOK_clicked()
{
    int pinnumber = QString (ui->lineEditPin->text()).toInt();
    qDebug() << "dllpin";
    qDebug() << pinnumber;
    emit sendSignalToDllPinInterface(pinnumber);
}

void pindialog::receiveWrongPinFromDLLPinCode()
{
    ui->lineEditPin->clear();
    ui->labelWrongPin->setStyleSheet("color: red");
    ui->labelWrongPin->setText("Väärä PIN");
}

void pindialog::receiveClosePinDialog()
{
    this->close();
    ui->lineEditPin->clear();
    ui->labelWrongPin->clear();
    ui->lineEditPin->setDisabled(0);
    ui->pushButtonOK->setDisabled(0);
}

void pindialog::receiveLockedPinFromDllPinCode()
{
    ui->lineEditPin->setDisabled(1);
    ui->pushButtonOK->setDisabled(1);
    ui->labelWrongPin->setStyleSheet("color: red");
    ui->labelWrongPin->setText("PIN lukittu");
}

void pindialog::keyPressEvent(QKeyEvent *eventKey)
{
    if(eventKey){
        qDebug() << "keyPressEvent";
        emit sendTimerResetToDllPinCode();
    }
}

void pindialog::mousePressEvent(QMouseEvent *eventMouse)
{
    if(eventMouse){
        emit sendTimerResetToDllPinCode();
    }
}

void pindialog::on_lineEditPin_textEdited(const QString &arg1)
{
    emit sendTimerResetToDllPinCode();
}
