#include "tilitapahtumat.h"
#include "ui_tilitapahtumat.h"

tilitapahtumat::tilitapahtumat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tilitapahtumat)
{
    ui->setupUi(this);
}

tilitapahtumat::~tilitapahtumat()
{
    delete ui;
}

void tilitapahtumat::receiveActionsFromEngineATM(QString actions10)
{
    ui->ActionsLabel->setText(actions10);
}

void tilitapahtumat::on_NextButton_clicked()
{
    emit NextTilitap();
}

void tilitapahtumat::on_PreviousButton_clicked()
{
    emit PreviousTilitap();
}
