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

class engineatm : public QObject
{
    Q_OBJECT
public:
    engineatm(QObject *parent = nullptr);
    ~engineatm();
    void testfunction();


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
    void sendBalanceToSaldo(QString);
    void requestBalance(int);
    void sendActions5ToSaldo(QByteArray);
    void requestActions(int);
    void sendActionsToTilitapahtumat(QString);
    void NextTilitapFromEngineATM(int);
    void PreviousTilitapFromEngineATM(int);

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
    void receiveActionsFromRestApi(QString);
    void receiveNextTilitap();
    void reveivePreviousTilitap();

private:
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
