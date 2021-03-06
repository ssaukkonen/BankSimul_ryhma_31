#ifndef DLLRESTAPI_H
#define DLLRESTAPI_H

#include "DLLRestAPI_global.h"
#include <QObject>
#include <QDebug>
#include "enginerestapi.h"

class DLLRESTAPI_EXPORT DLLRestAPI : public QObject
{
    Q_OBJECT
public:
    DLLRestAPI(QObject *parent = nullptr);
    ~DLLRestAPI();

public slots:
    void SignalFromEngineNosto(QString);
    void KorttiPinFromEngine(QString, QString);
    void receiveWrongPinFromEngineRestApi();
    void receiveCorrectPinFromEngineRestApi();
    void receiveIdFnameLnameFromEngineRestApi(int, QString, QString, QString);

    void receiveNostoNotWorking();
    void receiveNostoWorking();


    void receiveBalanceFromEngineRestApi(QString);
    void requestBalanceFromATMEngine(int);
    void receiveActions5FromEngineRestApi(QByteArray);
    void requestActionsFromATMEngine(int,int);
    void receiveActionsToDllRestApi(QByteArray);
    void receiveCleanVariablesFromEngineATM();
    void receiveLockedPinFromEngineRestApi();

    void receiveMoneyTodayFromEngine(int, QString, QString, QString, QString, QString);
    void receiveMoneyActionResultFromEngineRestApi(QString);

    void receiveRequestFutureActionsFromEngineATM(int,int);
    void receiveFutureActionsToDllRestApi(QByteArray);
    void receiveMoneyFutureFromEngine(int, QString, QString, QString, QString, QString);
    void receiveFutureActionResultFromEngineRestApi(QString);


signals:
    void SignalToEngineRestApi(QString);
    void KorttiPinToRestApiEngine(QString, QString);
    void sendWrongPinToEngineATM();
    void sendCorrectPinToEngineATM();
    void sendIdFnameLnameToEngineATM(int, QString, QString, QString);

    void sendNostoNotWorkingToEngineATM();
    void sendNostoWorkingToEngineATM();

    void sendBalanceToEngineATM(QString);
    void sendBalanceRequestToEngine(int);
    void sendActions5FromRestApi(QByteArray);
    void sendActionsRequestToEngineRestApi(int,int);
    void sendActionsFromRestApi(QByteArray);

    void sendMoneyTodayFromDllRestApi(int, QString, QString, QString, QString, QString);


    void sendMoneyActionResultFromDllRestApi(QString);

    void sendLockedPinToEngineATM();
    void sendRequestFutureActionsFromRestApi(int,int);
    void sendFutureActionsToEngineATM(QByteArray);
    void sendMoneyFutureFromDllRestApi(int, QString, QString, QString, QString, QString);
    void sendFutureActionResultFromDllRestApi(QString);

private:
    enginerestapi * pengineretsapi;
};

#endif // DLLRESTAPI_H
