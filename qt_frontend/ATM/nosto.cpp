#include "nosto.h"
#include "ui_nosto.h"

nosto::nosto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nosto)
{
    ui->setupUi(this);



}

nosto::~nosto()
{
    delete ui;

}

void nosto::on_button20_clicked()
{
    amount="-20";
    qDebug()<<amount;
    emit SignalToEngineFromNosto(amount);
}

void nosto::on_button40_clicked()
{
    amount="-40";
    qDebug()<<amount;
    emit SignalToEngineFromNosto(amount);
}

void nosto::on_button60_clicked()
{
    amount="-60";
    emit SignalToEngineFromNosto(amount);
}

void nosto::on_button100_clicked()
{
    amount="-100";
    emit SignalToEngineFromNosto(amount);
}

void nosto::on_button200_clicked()
{
    amount="-200";
    emit SignalToEngineFromNosto(amount);
}

void nosto::on_button500_clicked()
{
    amount="-500";
    emit SignalToEngineFromNosto(amount);
}

void nosto::receiveNostoNotWorkingFromEngine()
{
    qDebug()<<"NotWorking";
   ui->statusLabel->setText("Tilillä ei ole tarpeeksi rahaa");
}

void nosto::receiveNostoWorkingFromEngine()
{
    qDebug()<<"Working";
  ui->statusLabel->setText("Nosto onnistui");
}

void nosto::on_buttonSaldo_clicked()
{

}

void nosto::on_buttonMainMenu_clicked()
{

}

void nosto::on_buttonLogOut_clicked()
{
   emit logoutNosto();
}
