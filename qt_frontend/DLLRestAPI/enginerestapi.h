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
    void actions5Slot(QNetworkReply *reply);
    void receiveActionsRequestToEngineRestApi(int);
    void actionsSlot(QNetworkReply *reply);
    void receiveNextTilitapFromRestApi(int);
    void receivePreviousTilitapFromRestApi(int);

signals:
    void sendWrongPinToDllRestApi();
    void sendCorrectPinToDllRestApi();
    void sendIdFnameLnameToDllRestApi(int, QString, QString);
    void sendBalanceToDllRestApi(QString);
    void sendActions5ToDllRestApi(QString);
    void sendActionsToDllRestApi(QString);
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
    void actions5(QString);
    QNetworkAccessManager *actions5Manager;
    QNetworkReply *actions5Reply;
    QString id;
    QNetworkAccessManager *actionsManager;
    QNetworkReply *actionsReply;
    QNetworkAccessManager *actionsNextManager;
    QNetworkReply *actionsNextReply;
    QNetworkAccessManager *actionsPreviousManager;
    QNetworkReply *actionsPreviousReply;
};

#endif // ENGINERESTAPI_H
