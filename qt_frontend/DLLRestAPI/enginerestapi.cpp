#include "enginerestapi.h"

enginerestapi::enginerestapi(QObject *parent):QObject(parent)
{

}

enginerestapi::~enginerestapi()
{

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
