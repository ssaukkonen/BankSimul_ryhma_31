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
    void cleanVariablesEngineRestApi();

public slots:
    void SignalFromDllRestApi(QString);
    void nostoSlot(QNetworkReply *reply);
    void KorttiPinFromEngine(QString, QString);
    void pinSlot(QNetworkReply *reply);
    void BalanceFromEngine(int);
    void balanceSlot(QNetworkReply *reply);
    void idAccountSlot(QNetworkReply *reply);
    void actions5Slot(QNetworkReply *reply);
    void receiveActionsRequestToEngineRestApi(int,int);
    void actionsSlot(QNetworkReply *reply);
//    void receiveNextTilitapFromRestApi(int);
//    void receivePreviousTilitapFromRestApi(int);
    void receiveMoneyTodayFromDllRestApi(int, QString, QString, QString, QString, QString);
    void moneyTodaySlot(QNetworkReply *reply);

signals:
    void sendWrongPinToDllRestApi();
    void sendCorrectPinToDllRestApi();
    void sendIdFnameLnameToDllRestApi(int, QString, QString);

    void sendBalanceToDllRestApi(QString);
    void sendActions5ToDllRestApi(QByteArray);
    void sendActionsToDllRestApi(QByteArray);

    void sendLockedPinToDllRestApi();
    void sendMoneyActionResultFromEngineRestApi(QString);


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
    QNetworkAccessManager *moneyTodayManager;
    QNetworkReply *moneyTodayReply;
};

#endif // ENGINERESTAPI_H
