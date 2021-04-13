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

