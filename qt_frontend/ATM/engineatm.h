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

#include "saldo.h"
#include "tilitapahtumat.h"
#include "timerevent.h"


class engineatm : public QObject
{
    Q_OBJECT
public:
    engineatm(QObject *parent = nullptr);
    ~engineatm();
    void testfunction();


signals:
    void sendStartToTimer();
    void sendSignalToRfid();
    void sendSignalToExeFromEngineRfid();
//    void sendSignalToNosto();
    void sendSignalToDllRestApi(QString);
    void sendSignalPinToDLL();
    void sendKorttiPinToRestApi(QString, QString);
    void sendWrongPinToDLLPinCode();
    void sendFnameLnameToValikko(QString, QString);
    void sendClosePin();

    void sendBalanceToSaldo(QString);
    void requestBalance(int);
    void sendActions5ToSaldo(QByteArray);
    void requestActions(int,int);
    void sendActionsToTilitapahtumat(QByteArray);
    void NextTilitapFromEngineATM(int);
    void PreviousTilitapFromEngineATM(int);

    void sendCleanVariablesToDllRestApi();
    void sendReStartToDllSerialPort();
    void sendShowToMainWindow();
    void sendClosePinWindow();
    void sendCloseValikko();
    void sendTimerStop();
    void sendLockedPinToDllPinCode();
    void sendStartLockedPinTimer();
    void sendCloseSaldo();
    void sendCloseTilitapahtumat();
    void sendRequestFutureActionsFromEngineATM(int,int);
    void sendFutureActionsToTilitapahtumat(QByteArray);


public slots:
    void receiveSignalFromRfid(long long);
    void receiveSignalfromNosto(QString);
    void receiveSignalFromDllPin(int);
    void receiveWrongPinFromDllRestApi();
    void receiveCorrectPinFromDllRestApi();
    void receiveIdFnameLnameFromDllRestApi(int, QString, QString);

    void receiveBalanceFromDllRestApi(QString);
    void receiveSaldoMenu();
    void receiveActions5FromRestApi(QByteArray);
    void receiveTilitapahtumatMenu();
    void receiveActionsFromRestApi(QByteArray);
    void receiveTilitapahtumat(int);

    void receiveTimerReset();
    void logout();
    void receiveLockedPinFromDllRestApi();
    void receiveCloseFromSaldo();
    void receiveCloseFromTilitapahtumat();
    void receiveRequestFutureActionsFromTilitapahtumat(int);
    void receiveFutureActionsToEngineATM(QByteArray);


private:
    class timerEvent * ptimerEventATM;
    DLLSerialPort * pDLLSerialPort;
    DLLRestAPI * pDLLRestAPI;
    DLLPinCode * pDLLPinCode;
    Valikko * pValikko;
    saldo * psaldo;
    tilitapahtumat * ptilitapahtumat;
    long long kortti;
    int idAccount;

};

#endif // ENGINEATM_H
