#include "valikko.h"
#include "ui_valikko.h"

Valikko::Valikko(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Valikko)
{
    ui->setupUi(this);
}

Valikko::~Valikko()
{
    delete ui;
}

void Valikko::receiveFnameLnameFromEngineATM(QString fname, QString lname)
{
    qDebug() << "nimet";
    ui->labelFnameLname->setText(fname+" "+lname);
}

void Valikko::receiveCloseValikko()
{
    qDebug() << "closevalikko";
    this->close();
    ui->labelFnameLname->clear();
}

void Valikko::on_buttonValikkoLogout_clicked()
{
    emit logoutValikko();

}


void Valikko::on_SaldoButton_clicked()
{
    emit SaldoMenu();
}

void Valikko::on_TilitapahtumatButton_clicked()
{
    emit TilitapahtumatMenu();
}

void Valikko::on_buttonTilisiirto_clicked()
{
    emit TilisiirtoMenu();
}
