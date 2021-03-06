#include "tilisiirto.h"
#include "ui_tilisiirto.h"

tilisiirto::tilisiirto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tilisiirto)
{
    ui->setupUi(this); 
    ui->lineEditSumma->setValidator(new QRegExpValidator(QRegExp("[0-9]*\\.?[0-9]\\d{0,1}")));
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
    ui->labelTahti1->clear();
    ui->labelTahti2->clear();
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
    ui->labelTahti1->clear();
    ui->labelTahti2->clear();
    ui->labelNimi->clear();
    ui->labelOmaTili->clear();
    this->close();
}

void tilisiirto::receiveMoneyActionResultFromEngineATM(QString response_data)
{
    qDebug() << "response_data " << response_data;
    if(response_data == "0"){
        qDebug() << "money_action meni l??pi";
        ui->labelIlmoitus->setText("Maksu onnistui");
        ui->lineEditSumma->clear();
        ui->lineEditViite->clear();
        ui->lineEditViesti->clear();
        ui->lineEditTilinumero->clear();
    }
    if (response_data == "1"){
        qDebug() << "ei katetta";
        ui->labelIlmoitus->setText("Tilill?? ei katetta");
        ui->lineEditSumma->clear();
        ui->lineEditViite->clear();
        ui->lineEditViesti->clear();
        ui->lineEditTilinumero->clear();
    }
    if (response_data == "2"){
        qDebug() << "v????r?? tili";
        ui->labelIlmoitus->setText("Tilinumeroa ei l??ytynyt");
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

void tilisiirto::receiveFutureActionResultFromEngineATM(QString response_data)
{
    qDebug() << "response_data future" << response_data;
    if(response_data == "1"){
        qDebug() << "future_action meni l??pi";
        ui->labelIlmoitus->setText("Maksu tallennettu");
        ui->lineEditSumma->clear();
        ui->lineEditViite->clear();
        ui->lineEditViesti->clear();
        ui->lineEditTilinumero->clear();
    }
    if (response_data == "0"){
        qDebug() << "future_action ei mennyt l??pi";
        ui->labelIlmoitus->setText("Maksun tallennus ei onnistunut");
        ui->lineEditSumma->clear();
        ui->lineEditViite->clear();
        ui->lineEditViesti->clear();
        ui->lineEditTilinumero->clear();
    }
}

void tilisiirto::receivenimiToTilisiirtoFromEngineATM(QString nimi, QString accnumber)
{
    ui->labelNimi->setText(nimi);
    ui->labelOmaTili->setText(accnumber);
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
        ui->labelVirhe->setText("*T??yt?? pakolliset kent??t*");
        ui->labelTahti1->setText("*");
        ui->labelTahti2->setText("*");
    }
    else{
        QString summa = ui->lineEditSumma->text();
        QString viite = ui->lineEditViite->text();
        QString viesti = ui->lineEditViesti->text();
        QString tilinumero = ui->lineEditTilinumero->text();
        QString date = ui->dateEditPaiva->text();
        QString datetoday = QDate::currentDate().toString("yyyy-MM-dd");
        ui->labelVirhe->clear();
        ui->labelTahti1->clear();
        ui->labelTahti2->clear();
        if (date == datetoday){
            qDebug() << "t??n????n";
            emit sendMoneyTodayFromTilisiirto(summa, viite, viesti, tilinumero, date);
        }
        else {
            qDebug() << "tulevat";
            emit sendMoneyFutureFromTilisiirto(summa, viite, viesti, tilinumero, date);
        }
    }

}
