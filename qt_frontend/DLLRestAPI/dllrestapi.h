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
    void receiveIdFnameLnameFromEngineRestApi(int, QString, QString);
    void receiveBalanceFromEngineRestApi(QString);
    void requestBalanceFromATMEngine(int);
    void receiveActions5FromEngineRestApi(QByteArray);
    void requestActionsFromATMEngine(int,int);
    void receiveActionsToDllRestApi(QByteArray);
//    void receiveNextTilitapFromEngineATM(int);
//    void receivePreviousTilitapFromEngineATM(int);

signals:
    void SignalToEngineRestApi(QString);
    void KorttiPinToRestApiEngine(QString, QString);
    void sendWrongPinToEngineATM();
    void sendCorrectPinToEngineATM();
    void sendIdFnameLnameToEngineATM(int, QString, QString);
    void sendBalanceToEngineATM(QString);
    void sendBalanceRequestToEngine(int);
    void sendActions5FromRestApi(QByteArray);
    void sendActionsRequestToEngineRestApi(int,int);
    void sendActionsFromRestApi(QByteArray);
//    void sendNextTilitapFromRestApi(int);
//    void sendPreviousTilitapFromRestApi(int);

private:
    enginerestapi * pengineretsapi;
};

#endif // DLLRESTAPI_H
