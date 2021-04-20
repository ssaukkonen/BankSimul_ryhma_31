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
    id="1";

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

void enginerestapi::actions5(QString id2)
{
    //    QString id = QString::number(id2);
    id = "1"; //väliaikainen
    qDebug() << "balance tarkistus";
    QString site_url="http://localhost:3000/actions/actions5/"+id;
    QString credentials="automat123:pass123";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    actions5Manager = new QNetworkAccessManager(this);
    connect(actions5Manager, SIGNAL(finished (QNetworkReply*)),this, SLOT(actions5Slot(QNetworkReply*)));
    actions5Reply=actions5Manager->get(request);
}

void enginerestapi::actions5Slot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
//    qDebug()<<response_data;
    if(response_data.compare("")==0){
        qDebug() << "Virhe tietokantayhteydessä";
    }
    else
    {
//        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
//        QJsonArray json_array = json_doc.array();
//        QString listActions5;
//        foreach(const QJsonValue &value, json_array)
//        {
//            QJsonObject json_obj = value.toObject();
//            listActions5+=QString::number(json_obj["amount"].toDouble())+" €\t"+json_obj["date"].toString()+"\t"+json_obj["action_type"].toString()+"\t"+QString::number(json_obj["ref_num"].toDouble())+"\t"+json_obj["message"].toString()+"\t"+QString::number(json_obj["acc_sender"].toInt())+"\r\n";
//            qDebug() << listActions5;
//        }
        emit sendActions5ToDllRestApi(response_data);
    }
    actions5Reply->deleteLater();
    reply->deleteLater();
    actions5Manager->deleteLater();
}

void enginerestapi::receiveActionsRequestToEngineRestApi(int id2, int pagenumber)
{
    //    QString id = QString::number(id2);
    QString idaccount = "1"; //väliaikainen
    qDebug() << "tilitapahtuma tarkistus";
    QJsonObject json_obj;
    json_obj.insert("idaccount",idaccount);
    json_obj.insert("pagenumber",pagenumber);
    QString site_url="http://localhost:3000/actions/actions10/";
    QString credentials="automat123:pass123";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    actionsManager = new QNetworkAccessManager(this);
    connect(actionsManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(actionsSlot(QNetworkReply*)));
    actionsReply=actionsManager->post(request,QJsonDocument(json_obj).toJson());
}

void enginerestapi::actionsSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
//    qDebug()<<response_data;
    if(response_data.compare("")==0){
        qDebug() << "Virhe tietokantayhteydessä";
    }
    else
    {
//        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
//        QJsonArray json_array = json_doc.array();
//        QString listActions10;
//        foreach(const QJsonValue &value, json_array)
//        {
//            QJsonObject json_obj = value.toObject();
//            listActions10+=QString::number(json_obj["amount"].toDouble())+" €\t"+json_obj["date"].toString()+"\t"+json_obj["action_type"].toString()+"\t"+QString::number(json_obj["ref_num"].toDouble())+"\t"+json_obj["message"].toString()+"\t"+QString::number(json_obj["acc_sender"].toInt())+"\r\n";
//            qDebug() << listActions10;
//        }
        emit sendActionsToDllRestApi(response_data);
    }
    actionsReply->deleteLater();
    reply->deleteLater();
    actionsManager->deleteLater();
}

void enginerestapi::receiveRequestFutureActionsFromRestApi(int id2, int pagenumber)
{
    //    QString id = QString::number(id2);
    QString idaccount = "1"; //väliaikainen
    qDebug() << "tilitapahtuma tarkistus";
    QJsonObject json_obj;
    json_obj.insert("idaccount",idaccount);
    json_obj.insert("pagenumber",pagenumber);
    QString site_url="http://localhost:3000/future_actions/futureActions10/";
    QString credentials="automat123:pass123";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    futureActionsManager = new QNetworkAccessManager(this);
    connect(futureActionsManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(futureActionsSlot(QNetworkReply*)));
    futureActionsReply=futureActionsManager->post(request,QJsonDocument(json_obj).toJson());
}

void enginerestapi::futureActionsSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
//    qDebug()<<response_data;
    if(response_data.compare("")==0){
        qDebug() << "Virhe tietokantayhteydessä";
    }
    else
    {
        emit sendFutureActionsToDllRestApi(response_data);
    }
    futureActionsReply->deleteLater();
    reply->deleteLater();
    futureActionsManager->deleteLater();
}

//void enginerestapi::receiveNextTilitapFromRestApi(int id2)
//{

//}

//void enginerestapi::receivePreviousTilitapFromRestApi(int id2)
//{

//}

void enginerestapi::BalanceFromEngine(int id2)
{
//    qDebug() << balance;
//    QString id = QString::number(id2);
    id = "1"; //väliaikainen
    qDebug() << "balance tarkistus";
    QString site_url="http://localhost:3000/account/balance/"+id;
    QString credentials="automat123:pass123";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    balanceManager = new QNetworkAccessManager(this);
    connect(balanceManager, SIGNAL(finished (QNetworkReply*)),this, SLOT(balanceSlot(QNetworkReply*)));
    balanceReply=balanceManager->get(request);
}

void enginerestapi::balanceSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    qDebug()<<response_data;
    if(response_data.compare("")==0){
        qDebug() << "Virhe tietokantayhteydessä";
    }
    else if(response_data.compare("0")==0){
        qDebug() << "Ei saldoa";
    }
    else
    {
        QString balance = response_data;
        qDebug() << balance;
        emit sendBalanceToDllRestApi(balance);
            actions5(id);
    }
    balanceReply->deleteLater();
    reply->deleteLater();
    balanceManager->deleteLater();
}
