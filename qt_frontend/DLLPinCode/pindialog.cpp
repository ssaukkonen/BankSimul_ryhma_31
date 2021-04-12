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
