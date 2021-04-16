#include "enginerestapi.h"

enginerestapi::enginerestapi(QObject *parent):QObject(parent)
{

}

enginerestapi::~enginerestapi()
{

}

void enginerestapi::cleanVariablesEngineRestApi()
{
    korttiToId="0";
}

void enginerestapi::SignalFromDllRestApi(QString amount)
{
    qDebug() << amount;
    qDebug() << "enginerestapi";
    QString id="1";

    QJsonObject json_obj;
    json_obj.insert("acc_number",3333);
    json_obj.insert("balance",amount);
    QString site_url="http://localhost:3000/account/"+id;
    QString credentials="automat123:pass123";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    nostoManager = new QNetworkAccessManager(this);
    connect(nostoManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(nostoSlot(QNetworkReply*)));
    nostoReply=nostoManager->put(request,QJsonDocument(json_obj).toJson());
}

void enginerestapi::nostoSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    if(response_data.compare("-4078")==0){
        qDebug() << "Virhe tietokantayhteydessä";
    }
    else if(response_data.compare("0")==0){
        qDebug() << "Nosto ei onnistu";
    }
    else{
        qDebug() << "Nosto onnistui";
    }

    nostoReply->deleteLater();
    reply->deleteLater();
    nostoManager->deleteLater();
}

void enginerestapi::KorttiPinFromEngine(QString Qkortti, QString Qpin)
{
    qDebug() << Qkortti << Qpin;
    qDebug() << "pin tarkistus";
    QJsonObject json_obj;
    korttiToId = Qkortti;
    json_obj.insert("username",Qkortti);
    json_obj.insert("password",Qpin);
    QString site_url="http://localhost:3000/login/";
    QString credentials="automat123:pass123";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    pinManager = new QNetworkAccessManager(this);
    connect(pinManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(pinSlot(QNetworkReply*)));
    pinReply=pinManager->post(request,QJsonDocument(json_obj).toJson());
}

void enginerestapi::pinSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    if(response_data.compare("")==0){
        qDebug() << "Virhe yhteydessä";
    }
    else if(response_data.compare("false")==0){
        qDebug() << "Väärä PIN";
        emit sendWrongPinToDllRestApi();
    }
   else if(response_data.compare("true")==0){
        qDebug() << "Oikea PIN";
        emit sendCorrectPinToDllRestApi();
        receiveIdAccount();
    }
    else if(response_data.compare("locked")==0){
        qDebug() << "PIN lukittu";
        emit sendLockedPinToDllRestApi();
    }
    else{
        qDebug() << "Virhe";
    }

    pinReply->deleteLater();
    reply->deleteLater();
    pinManager->deleteLater();
}

void enginerestapi::idAccountSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    if(response_data.compare("")==0){
        qDebug() << "Virhe tietokantayhteydessä";
    }
    else{
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    int idAccount=json_obj["id_account"].toInt();
    QString fname=json_obj["fname"].toString();
    QString lname=json_obj["lname"].toString();
    qDebug() << idAccount << fname << lname;
    emit sendIdFnameLnameToDllRestApi(idAccount, fname, lname);
    }
    idAccountReply->deleteLater();
    reply->deleteLater();
    idAccountManager->deleteLater();
}

void enginerestapi::receiveIdAccount()
{
    QJsonObject json_obj;

    json_obj.insert("card_number",korttiToId);
    QString site_url="http://localhost:3000/card/card_number";
    QString credentials="automat123:pass123";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    idAccountManager = new QNetworkAccessManager(this);
    connect(idAccountManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(idAccountSlot(QNetworkReply*)));
    idAccountReply=idAccountManager->post(request,QJsonDocument(json_obj).toJson());
}
