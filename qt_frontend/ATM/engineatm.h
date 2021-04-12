#ifndef ENGINEATM_H
#define ENGINEATM_H

#include <QObject>
#include <QWidget>
#include "dllserialport.h"
#include "dllrestapi.h"
#include <QDebug>
//#include "pin.h"
#include "dllpincode.h"

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
    void sendSignalPinToDLL();

public slots:
    void receiveSignalFromRfid(long long);
    void receiveSignalfromNosto(QString);
    void receiveSignalFromDllPin(int);

private:
    DLLSerialPort * pDLLSerialPort;
    DLLRestAPI * pDLLRestAPI;
    DLLPinCode * ppinengine;
    long long kortti;
};

#endif // ENGINEATM_H
