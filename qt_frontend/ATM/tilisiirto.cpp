#include "tilisiirto.h"
#include "ui_tilisiirto.h"

tilisiirto::tilisiirto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tilisiirto)
{
    ui->setupUi(this); 
    ui->lineEditSumma->setValidator(new QDoubleValidator);
    ui->lineEditViite->setValidator(new QDoubleValidator);
    ui->lineEditTilinumero->setValidator(new QDoubleValidator);
}

tilisiirto::~tilisiirto()
{
    delete ui;
}

void tilisiirto::setDefaults()
{
    ui->dateEditPaiva->setDate(QDate::currentDate());
    ui->dateEditPaiva->setMinimumDate(QDate::currentDate());
    ui->labelVirhe->clear();
}

void tilisiirto::on_lineEditTilinumero_textEdited(const QString &arg1)
{
        emit sendTimerResetToEngineATMFromTilisiirto();
}

void tilisiirto::on_lineEditSumma_textEdited(const QString &arg1)
{
        emit sendTimerResetToEngineATMFromTilisiirto();
}

void tilisiirto::on_lineEditViite_textEdited(const QString &arg1)
{
        emit sendTimerResetToEngineATMFromTilisiirto();
}

void tilisiirto::on_lineEditViesti_textEdited(const QString &arg1)
{
        emit sendTimerResetToEngineATMFromTilisiirto();
}

void tilisiirto::keyPressEvent(QKeyEvent *eventKey)
{
    if(eventKey){
        emit sendTimerResetToEngineATMFromTilisiirto();
    }
}

void tilisiirto::mousePressEvent(QMouseEvent *eventMouse)
{
    if(eventMouse){
        emit sendTimerResetToEngineATMFromTilisiirto();
    }
}

void tilisiirto::receiveCloseTilisiirto()
{
    ui->lineEditSumma->clear();
    ui->lineEditViite->clear();
    ui->lineEditViesti->clear();
    ui->lineEditTilinumero->clear();
    this->close();
}

void tilisiirto::on_buttonTakaisinTilisiirto_clicked()
{
    emit sendCloseFromTilisiirto();
}

void tilisiirto::on_buttonLogoutTilisiirto_clicked()
{
    emit logoutTilisiirto();
}

void tilisiirto::on_buttonSendValues_clicked()
{
    if (ui->lineEditSumma->text() == NULL || ui->lineEditTilinumero->text() == NULL){
        ui->labelVirhe->setText("*Täytä pakolliset kentät*");
    }
    else{
        QString summa = ui->lineEditSumma->text();
        QString viite = ui->lineEditViite->text();
        QString viesti = ui->lineEditViesti->text();
        QString tilinumero = ui->lineEditTilinumero->text();
        QString date = ui->dateEditPaiva->text();
        QString datetoday = QDate::currentDate().toString("yyyy-MM-dd");
        if (date == datetoday){
            qDebug() << "tänään";
            emit sendMoneyTodayFromTilisiirto(summa, viite, viesti, tilinumero, date);
        }
        else {
            qDebug() << "tulevat";
            //emit sendMoneyFutureFromTilisiirto(summa, viite, viesti, tilinumero, date);
        }
    }

}
