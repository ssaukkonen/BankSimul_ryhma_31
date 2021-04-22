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
    emit sendSaldoKyselyToEngine();
    ui->saldoLabel->clear();
    ui->statusLabel->clear();
    ui->buttonSaldo->hide();
    ui->button20->show();
    ui->button40->show();
    ui->button40->show();
    ui->button60->show();
    ui->button100->show();
    ui->button200->show();
    ui->button500->show();
    ui->label->show();
    ui->labelNimi->clear();
}

void nosto::on_button20_clicked()
{
    amount="-20";
    emit sendTimerResetToEngineFromNosto();
    emit SignalToEngineFromNosto(amount);
}

void nosto::on_button40_clicked()
{
    amount="-40";
    emit sendTimerResetToEngineFromNosto();
    emit SignalToEngineFromNosto(amount);
}

void nosto::on_button60_clicked()
{
    amount="-60";
    emit sendTimerResetToEngineFromNosto();
    emit SignalToEngineFromNosto(amount);
}

void nosto::on_button100_clicked()
{
    amount="-100";
    emit sendTimerResetToEngineFromNosto();
    emit SignalToEngineFromNosto(amount);
}

void nosto::on_button200_clicked()
{
    amount="-200";
    emit sendTimerResetToEngineFromNosto();
    emit SignalToEngineFromNosto(amount);
}

void nosto::on_button500_clicked()
{
    amount="-500";
    emit sendTimerResetToEngineFromNosto();
    emit SignalToEngineFromNosto(amount);
}

void nosto::on_buttonSaldo_clicked()
{
    emit sendTimerResetToEngineFromNosto();
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
    ui->saldoLabel->clear();
    ui->label->hide();
    ui->button20->hide();
    ui->button40->hide();
    ui->button40->hide();
    ui->button60->hide();
    ui->button100->hide();
    ui->button200->hide();
    ui->button500->hide();
}

void nosto::receiveNostoWorkingFromEngine()
{
    ui->statusLabel->setText("Nosto onnistui");
    ui->buttonSaldo->setText("Näytä saldo");
    ui->saldoLabel->clear();
    ui->buttonSaldo->show();
    ui->label->hide();
    ui->button20->hide();
    ui->button40->hide();
    ui->button40->hide();
    ui->button60->hide();
    ui->button100->hide();
    ui->button200->hide();
    ui->button500->hide();
}

void nosto::receiveCloseNosto()
{
    this->close();
    ui->saldoLabel->clear();
    ui->statusLabel->clear();
    ui->buttonSaldo->hide();
    ui->labelNimi->clear();
}

void nosto::receiveBalanceToNostoFromEngineATM(QString balance)
{
    ui->saldoLabel->setText("Saldo: "+balance+" €");
}

void nosto::receivenimiToNostoFromEngineATM(QString nimi)
{
    ui->labelNimi->setText(nimi);
}


void nosto::mousePressEvent(QMouseEvent *eventMouse)
{
    if(eventMouse){
        emit sendTimerResetToEngineFromNosto();
    }
}
