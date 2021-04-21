#include "nosto.h"
#include "ui_nosto.h"

nosto::nosto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nosto)
{
    ui->setupUi(this);


    ui->buttonSaldo->hide();
}

nosto::~nosto()
{
    delete ui;

}

void nosto::setNostoDefaults()
{
    ui->saldoLabel->clear();
    ui->statusLabel->clear();
    ui->buttonSaldo->hide();
}

void nosto::on_button20_clicked()
{
    amount="-20";
    emit SignalToEngineFromNosto(amount);
}

void nosto::on_button40_clicked()
{
    amount="-40";
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

void nosto::on_buttonSaldo_clicked()
{
    emit sendSaldoKyselyToEngine();
}

void nosto::on_buttonBack_clicked()
{
    emit sendCloseFromNosto();
}

void nosto::on_buttonLogOut_clicked()
{
    emit logoutNosto();
}

void nosto::receiveNostoNotWorkingFromEngine()
{
    ui->statusLabel->setText("Tilillä ei tarpeeksi rahaa");
}

void nosto::receiveNostoWorkingFromEngine()
{
    ui->statusLabel->setText("Nosto onnistui");
    ui->buttonSaldo->setText("Näytä saldo");
    ui->buttonSaldo->show();
}

void nosto::receiveCloseNosto()
{
    this->close();
    ui->saldoLabel->clear();
    ui->statusLabel->clear();
    ui->buttonSaldo->hide();
}

void nosto::receiveBalanceToNostoFromEngineATM(QString balance)
{
   ui->saldoLabel->setText("Saldo: "+balance+" €");
}


void nosto::mousePressEvent(QMouseEvent *eventMouse)
{
    if(eventMouse){
        emit sendTimerResetToEngineFromNosto();
    }
}
