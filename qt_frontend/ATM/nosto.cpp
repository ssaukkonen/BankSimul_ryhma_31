#include "nosto.h"
#include "ui_nosto.h"

nosto::nosto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nosto)
{
    ui->setupUi(this);
    pengineAtmNosto = new engineatm;
    connect(this,SIGNAL(SignalToEngineFromNosto(QString)),pengineAtmNosto,SLOT(receiveSignalfromNosto(QString)),Qt::QueuedConnection);
}

nosto::~nosto()
{
    delete ui;
    delete pengineAtmNosto;
}

void nosto::on_button20_clicked()
{
    amount="20";
    emit SignalToEngineFromNosto(amount);
}
