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

void tilitapahtumat::receiveActionsFromEngineATM(QByteArray actions10)
{
    //    ui->ActionsLabel->setText(actions10);

    QJsonDocument doc = QJsonDocument::fromJson(actions10);
    QJsonArray array_doc = doc.array();
    int r=0;
    foreach(const QJsonValue &value, array_doc){
        QJsonObject json_obj = value.toObject();
        auto *it = new QTableWidgetItem(QString::number(json_obj["amount"].toDouble()));
        ui->tableWidget1->setItem(r, 0, it);
        auto *it2 = new QTableWidgetItem(json_obj["date"].toString());
        ui->tableWidget1->setItem(r, 1, it2);
        auto *it3 = new QTableWidgetItem(json_obj["action_type"].toString());
        ui->tableWidget1->setItem(r, 2, it3);
        auto *it4 = new QTableWidgetItem(QString::number(json_obj["ref_num"].toInt()));
        ui->tableWidget1->setItem(r, 3, it4);
        auto *it5 = new QTableWidgetItem(json_obj["message"].toString());
        ui->tableWidget1->setItem(r, 4, it5);
        auto *it6 = new QTableWidgetItem(QString::number(json_obj["acc_sender"].toInt()));
        ui->tableWidget1->setItem(r, 5, it6);
        r++;
    }

}

void tilitapahtumat::on_NextButton_clicked()
{
    pagenumber+=10;
    ui ->PreviousButton ->setDisabled(0);
    qDebug() << pagenumber;
    emit NextTilitap(pagenumber);
    ui ->tableWidget1 ->clear();
}

void tilitapahtumat::on_PreviousButton_clicked()
{
    pagenumber-=10;
    if(pagenumber == 0)
    {
        ui ->PreviousButton ->setDisabled(1);
    }
    qDebug() << pagenumber;
    emit PreviousTilitap(pagenumber);
    ui ->tableWidget1 ->clear();
}
