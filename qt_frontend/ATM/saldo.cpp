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
        QString date = json_obj["date"].toString() ;
        int pos = date.lastIndexOf(QChar('T'));
        ui->tableWidget->setItem(r, 1, new QTableWidgetItem(date.left(pos)));
        auto *it3 = new QTableWidgetItem(json_obj["action_type"].toString());
        ui->tableWidget->setItem(r, 2, it3);
        if (QString::number(json_obj["ref_num"].toInt())=="0"){
            ui->tableWidget->setItem(r, 3, new QTableWidgetItem(""));
        }
        else{
            auto *it4 = new QTableWidgetItem(QString::number(json_obj["ref_num"].toInt()));
            ui->tableWidget->setItem(r, 3, it4);
        }
        auto *it5 = new QTableWidgetItem(json_obj["message"].toString());
        ui->tableWidget->setItem(r, 4, it5);
        if (QString::number(json_obj["acc_sender"].toInt())=="0"){
            ui->tableWidget->setItem(r, 5, new QTableWidgetItem(""));
        }
        else{
            auto *it6 = new QTableWidgetItem(QString::number(json_obj["acc_sender"].toInt()));
            ui->tableWidget->setItem(r, 5, it6);
        }
        r++;
    }
}

void saldo::receiveCloseSaldo()
{
    qDebug() << "receiveCloseSaldo";
    this->close();
    ui->tableWidget->clearContents();
    ui->labelNimi->clear();
}

void saldo::receivenimiToSaldoFromEngineATM(QString nimi)
{
    ui->labelNimi->setText(nimi);
}

void saldo::on_buttonTakaisinSaldo_clicked()
{
    emit sendCloseFromSaldo();
}

void saldo::on_buttonLogoutSaldo_clicked()
{
    emit logoutSaldo();
}
