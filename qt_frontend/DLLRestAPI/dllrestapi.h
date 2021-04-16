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
    void receiveCleanVariablesFromEngineATM();
    void receiveLockedPinFromEngineRestApi();

signals:
    void SignalToEngineRestApi(QString);
    void KorttiPinToRestApiEngine(QString, QString);
    void sendWrongPinToEngineATM();
    void sendCorrectPinToEngineATM();
    void sendIdFnameLnameToEngineATM(int, QString, QString);
    void sendLockedPinToEngineATM();

private:
    enginerestapi * pengineretsapi;
};

#endif // DLLRESTAPI_H
