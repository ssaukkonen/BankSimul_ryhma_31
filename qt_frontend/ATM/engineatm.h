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
#include "timerevent.h"
#include "nosto.h"

class engineatm : public QObject
{
    Q_OBJECT
public:
    engineatm(QObject *parent = nullptr);
    ~engineatm();


signals:
    void sendStartToTimer();
    void sendSignalToRfid();
    void sendSignalToExeFromEngineRfid();
   // void sendSignalToNosto();
    void sendSignalToDllRestApi(QString);
    void sendSignalPinToDLL();
    void sendKorttiPinToRestApi(QString, QString);
    void sendWrongPinToDLLPinCode();
    void sendFnameLnameToValikko(QString, QString);
    void sendClosePin();
    void sendCleanVariablesToDllRestApi();
    void sendReStartToDllSerialPort();
    void sendShowToMainWindow();
    void sendClosePinWindow();
    void sendCloseValikko();
    void sendTimerStop();
    void sendLockedPinToDllPinCode();
    void sendStartLockedPinTimer();
    void sendNostoNotWorkingToNostoFromEngine();
    void sendNostoWorkingToNostoFromEngine();


public slots:
    void receiveSignalFromRfid(long long);
    void receiveSignalfromNosto(QString);
    void receiveSignalFromDllPin(int);
    void receiveWrongPinFromDllRestApi();
    void receiveCorrectPinFromDllRestApi();
    void receiveIdFnameLnameFromDllRestApi(int, QString, QString);
    void receiveTimerReset();
    void logout();
    void receiveLockedPinFromDllRestApi();
    void receiveNostoNotWorkingFromDllRestApi();
    void receiveNostoWorkingFromDllRestApi();
    void receiveOpenNostoFromValikko();

private:
    class timerEvent * ptimerEventATM;
    DLLSerialPort * pDLLSerialPort;
    DLLRestAPI * pDLLRestAPI;
    DLLPinCode * pDLLPinCode;
    Valikko * pValikko;
    nosto * pnosto;
    long long kortti;
    int idAccount;

};

#endif // ENGINEATM_H
