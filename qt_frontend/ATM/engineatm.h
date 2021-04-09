#ifndef ENGINEATM_H
#define ENGINEATM_H

#include <QObject>
#include <QWidget>
#include "dllserialport.h"
#include "dllrestapi.h"
#include <QDebug>
#include "pin.h"

class engineatm : public QObject
{
    Q_OBJECT
public:
    engineatm(QObject *parent = nullptr);
    ~engineatm();

signals:
    void sendSignalToRfid();
    void sendSignalToExeFromEngineRfid();
//    void sendSignalToNosto();
    void sendSignalToDllRestApi(QString);
    void sendKorttiToPin(long long);

public slots:
    void receiveSignalFromRfid(long long);
    void receiveSignalfromNosto(QString);

private:
    DLLSerialPort * pDLLSerialPort;
    DLLRestAPI * pDLLRestAPI;
    pin * ppinengine;
};

#endif // ENGINEATM_H
