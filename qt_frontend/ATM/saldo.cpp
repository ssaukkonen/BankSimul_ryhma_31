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

void saldo::receiveActions5FromEngineATM(QByteArray actions5x)
{
    QJsonDocument doc = QJsonDocument::fromJson(actions5x);
    QJsonArray array_doc = doc.array();
    int r=0;
    foreach(const QJsonValue &value, array_doc){
        QJsonObject json_obj = value.toObject();
        auto *it = new QTableWidgetItem(QString::number(json_obj["amount"].toDouble()));
        ui->tableWidget->setItem(r, 0, it);
        auto *it2 = new QTableWidgetItem(json_obj["date"].toString());
        ui->tableWidget->setItem(r, 1, it2);
        auto *it3 = new QTableWidgetItem(json_obj["action_type"].toString());
        ui->tableWidget->setItem(r, 2, it3);
        auto *it4 = new QTableWidgetItem(QString::number(json_obj["ref_num"].toInt()));
        ui->tableWidget->setItem(r, 3, it4);
        auto *it5 = new QTableWidgetItem(json_obj["message"].toString());
        ui->tableWidget->setItem(r, 4, it5);
        auto *it6 = new QTableWidgetItem(QString::number(json_obj["acc_sender"].toInt()));
        ui->tableWidget->setItem(r, 5, it6);
        r++;
    }
}
