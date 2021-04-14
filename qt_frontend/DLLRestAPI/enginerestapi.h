#ifndef ENGINERESTAPI_H
#define ENGINERESTAPI_H

#include <QObject>

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class enginerestapi : public QObject
{
    Q_OBJECT
public:
    enginerestapi(QObject *parent = nullptr);
    ~enginerestapi();

public slots:
    void SignalFromDllRestApi(QString);
    void nostoSlot(QNetworkReply *reply);
    void KorttiPinFromEngine(QString, QString);
    void pinSlot(QNetworkReply *reply);
    void BalanceFromEngine(int);
    void balanceSlot(QNetworkReply *reply);
    void idAccountSlot(QNetworkReply *reply);

signals:
    void sendWrongPinToDllRestApi();
    void sendCorrectPinToDllRestApi();
    void sendIdFnameLnameToDllRestApi(int, QString, QString);
    void sendBalanceToDllRestApi(QString);

private:
    QNetworkAccessManager *nostoManager;
    QNetworkReply *nostoReply;
    QNetworkAccessManager *pinManager;
    QNetworkReply *pinReply;
    void receiveIdAccount();
    QString korttiToId;
    QNetworkAccessManager *idAccountManager;
    QNetworkReply *idAccountReply;
    QNetworkAccessManager *balanceManager;
    QNetworkReply *balanceReply;
};

#endif // ENGINERESTAPI_H
