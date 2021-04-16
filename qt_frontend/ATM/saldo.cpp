#include "saldo.h"
#include "ui_saldo.h"

saldo::saldo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saldo)
{
    ui->setupUi(this);
}

saldo::~saldo()
{
    delete ui;
}

void saldo::receiveBalanceFromEngineATM(QString balance)
{
    ui->SaldoLabel->setText(balance+" €");
}

void saldo::receiveActions5FromEngineATM(QString actions5x)
{
    ui->Actions5Label->setText(actions5x);
}
