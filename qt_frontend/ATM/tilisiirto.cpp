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
    ui->labelIlmoitus->clear();
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
    ui->labelVirhe->clear();
    ui->labelIlmoitus->clear();
    this->close();
}

void tilisiirto::receiveMoneyActionResultFromEngineATM(QString response_data)
{
    qDebug() << "response_data " << response_data;
    if(response_data == "0"){
        qDebug() << "money_action meni läpi";
        ui->labelIlmoitus->setText("Maksu onnistui");
        ui->lineEditSumma->clear();
        ui->lineEditViite->clear();
        ui->lineEditViesti->clear();
        ui->lineEditTilinumero->clear();
    }
    if (response_data == "1"){
        qDebug() << "ei katetta";
        ui->labelIlmoitus->setText("Tilillä ei katetta");
        ui->lineEditSumma->clear();
        ui->lineEditViite->clear();
        ui->lineEditViesti->clear();
        ui->lineEditTilinumero->clear();
    }
    if (response_data == "2"){
        qDebug() << "väärä tili";
        ui->labelIlmoitus->setText("Tilinumeroa ei löytynyt");
        ui->lineEditSumma->clear();
        ui->lineEditViite->clear();
        ui->lineEditViesti->clear();
        ui->lineEditTilinumero->clear();
    }
    if (response_data == "3"){
        qDebug() << "error";
        ui->labelIlmoitus->setText("Tapahtui virhe");
        ui->lineEditSumma->clear();
        ui->lineEditViite->clear();
        ui->lineEditViesti->clear();
        ui->lineEditTilinumero->clear();
    }
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
