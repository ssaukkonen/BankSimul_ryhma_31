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
        QString date = json_obj["date"].toString() ;
        int pos = date.lastIndexOf(QChar('T'));
        ui->tableWidget1->setItem(r, 1, new QTableWidgetItem(date.left(pos)));
        auto *it3 = new QTableWidgetItem(json_obj["action_type"].toString());
        ui->tableWidget1->setItem(r, 2, it3);
        if (QString::number(json_obj["ref_num"].toInt())=="0"){
            ui->tableWidget1->setItem(r, 3, new QTableWidgetItem(""));
        }
        else{
            auto *it4 = new QTableWidgetItem(QString::number(json_obj["ref_num"].toInt()));
            ui->tableWidget1->setItem(r, 3, it4);
        }
        auto *it5 = new QTableWidgetItem(json_obj["message"].toString());
        ui->tableWidget1->setItem(r, 4, it5);
        if (QString::number(json_obj["acc_sender"].toInt())=="0"){
            ui->tableWidget1->setItem(r, 5, new QTableWidgetItem(""));
        }
        else{
            auto *it6 = new QTableWidgetItem(QString::number(json_obj["acc_sender"].toInt()));
            ui->tableWidget1->setItem(r, 5, it6);
        }
        r++;
    }

}

void tilitapahtumat::receiveFutureActionsToTilitapahtumat(QByteArray futureActions10)
{
    QJsonDocument doc = QJsonDocument::fromJson(futureActions10);
    QJsonArray array_doc = doc.array();
    int r=0;
    foreach(const QJsonValue &value, array_doc){
        QJsonObject json_obj = value.toObject();
        auto *it = new QTableWidgetItem(QString::number(json_obj["amount"].toDouble()));
        ui->tableWidget1->setItem(r, 0, it);
        QString date = json_obj["action_date"].toString() ;
        int pos = date.lastIndexOf(QChar('T'));
        ui->tableWidget1->setItem(r, 1, new QTableWidgetItem(date.left(pos)));
        auto *it3 = new QTableWidgetItem(json_obj["action_type"].toString());
        ui->tableWidget1->setItem(r, 2, it3);
        if (QString::number(json_obj["ref_num"].toInt())=="0"){
            ui->tableWidget1->setItem(r, 3, new QTableWidgetItem(""));
        }
        else{
            auto *it4 = new QTableWidgetItem(QString::number(json_obj["ref_num"].toInt()));
            ui->tableWidget1->setItem(r, 3, it4);
        }
        auto *it5 = new QTableWidgetItem(json_obj["message"].toString());
        ui->tableWidget1->setItem(r, 4, it5);
        if (QString::number(json_obj["recipient_number"].toInt())=="0"){
            ui->tableWidget1->setItem(r, 5, new QTableWidgetItem(""));
        }
        else{
            auto *it6 = new QTableWidgetItem(QString::number(json_obj["recipient_number"].toInt()));
            ui->tableWidget1->setItem(r, 5, it6);
        }
        r++;
    }
}

void tilitapahtumat::receivenimiToTilitapahtumatFromEngineATM(QString nimi)
{
    ui->labelNimi->setText(nimi);
}

void tilitapahtumat::receiveBalanceToTilitapahtumat(QString balance)
{
    ui->saldoLabel->setText("Saldo: "+balance+" €");
}

void tilitapahtumat::on_NextButton_clicked()
{
    switch (tapahtuma){
    case 0:
        emit sendTimerResetFromTilitapahtumat();
        pagenumber+=10;
        ui ->PreviousButton ->setDisabled(0);
        qDebug() << pagenumber;
        emit requestActionsFromTilitapahtumat(pagenumber);
        ui ->tableWidget1->clearContents();
        break;
    case 1:
        emit sendTimerResetFromTilitapahtumat();
        pagenumber+=10;
        ui ->PreviousButton ->setDisabled(0);
        qDebug() << pagenumber;
        emit requestFutureActionsFromTilitapahtumat(pagenumber);
        ui ->tableWidget1->clearContents();
        break;
    }
}

void tilitapahtumat::on_PreviousButton_clicked()
{
    switch (tapahtuma){
    case 0:
        emit sendTimerResetFromTilitapahtumat();
        pagenumber-=10;
        if(pagenumber == 0)
        {
            ui ->PreviousButton ->setDisabled(1);
        }
        qDebug() << pagenumber;
        emit requestActionsFromTilitapahtumat(pagenumber);
        ui ->tableWidget1->clearContents();
        break;
    case 1:
        emit sendTimerResetFromTilitapahtumat();
        pagenumber-=10;
        if(pagenumber == 0)
        {
            ui ->PreviousButton ->setDisabled(1);
        }
        qDebug() << pagenumber;
        emit requestFutureActionsFromTilitapahtumat(pagenumber);
        ui ->tableWidget1->clearContents();
        break;
    }
}

void tilitapahtumat::on_buttonTakaisinTilitapahtumat_clicked()
{
    emit sendCloseFromTilitapahtumat();
}

void tilitapahtumat::receiveCloseTilitapahtumat()
{
    this->close();
    ui->tableWidget1->clearContents();
    ui->labelNimi->clear();
    ui->saldoLabel->clear();
    ui->label_2->setText("Tilitapahtumat");
    ui->buttonTulevat->setText("Tulevat maksut");
    tapahtuma = 0;
    pagenumber = 0;
}

void tilitapahtumat::on_buttonLogoutTilitapahtumat_clicked()
{
    emit logoutTilitapahtumat();
}

void tilitapahtumat::on_buttonTulevat_clicked()
{
    emit sendTimerResetFromTilitapahtumat();
    qDebug() << "buttonTulevat painettu";
    switch (tapahtuma){
    case 0:
        qDebug() << "0";
        ui->label_2->setText("Tulevat maksut");
        ui->buttonTulevat->setText("Menneet tapahtumat");
        tapahtuma = 1;
        pagenumber = 0;
        emit requestFutureActionsFromTilitapahtumat(pagenumber);
        ui ->tableWidget1->clearContents();
        break;
    case 1:
        qDebug() << "1";
        ui->label_2->setText("Tilitapahtumat");
        ui->buttonTulevat->setText("Tulevat maksut");
        tapahtuma = 0;
        pagenumber = 0;
        emit requestActionsFromTilitapahtumat(pagenumber);
        ui ->tableWidget1->clearContents();
        break;
    }
}
