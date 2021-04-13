#ifndef ENGINEATM_H
#define ENGINEATM_H

#include <QObject>
#include <QWidget>
#include "dllserialport.h"
#include "dllrestapi.h"
#include <QDebug>
//#include "pin.h"
#include "dllpincode.h"
#include "valikko.h"

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
    void sendKorttiPinToRestApi(QString, QString);
    void sendWrongPinToDLLPinCode();
    void sendFnameLnameToValikko(QString, QString);
    void sendClosePin();

public slots:
    void receiveSignalFromRfid(long long);
    void receiveSignalfromNosto(QString);
    void receiveSignalFromDllPin(int);
    void receiveWrongPinFromDllRestApi();
    void receiveCorrectPinFromDllRestApi();
    void receiveIdFnameLnameFromDllRestApi(int, QString, QString);

private:
    DLLSerialPort * pDLLSerialPort;
    DLLRestAPI * pDLLRestAPI;
    DLLPinCode * pDLLPinCode;
    Valikko * pValikko;
    long long kortti;
    int idAccount;
};

#endif // ENGINEATM_H
