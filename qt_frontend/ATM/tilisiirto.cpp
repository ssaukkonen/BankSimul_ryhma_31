#include "tilisiirto.h"
#include "ui_tilisiirto.h"

tilisiirto::tilisiirto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tilisiirto)
{
    ui->setupUi(this);
}

tilisiirto::~tilisiirto()
{
    delete ui;
}
