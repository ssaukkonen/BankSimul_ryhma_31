#include "engineatm.h"

engineatm::engineatm(QObject *parent):QObject(parent)
{
    ptimerEventATM = new class timerEvent;
    pDLLSerialPort = new DLLSerialPort;
    pDLLRestAPI = new DLLRestAPI;
    pDLLPinCode = new DLLPinCode;
    pValikko = new Valikko;

    psaldo = new saldo;
    ptilitapahtumat = new tilitapahtumat;
//    connect(this,SIGNAL(sendSignalToRfid()),pDllrfid,SLOT(receiveSignalFromExe()),Qt::QueuedConnection);

    connect(this,SIGNAL(sendStartToTimer()),ptimerEventATM,SLOT(receiveStartFromEngineATM()),Qt::QueuedConnection);
    connect(pDLLSerialPort,SIGNAL(sendSignalToExeFromRfid(long long)),this,SLOT(receiveSignalFromRfid(long long)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendSignalToDllRestApi(QString)),pDLLRestAPI,SLOT(SignalFromEngineNosto(QString)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendSignalPinToDLL()),pDLLPinCode,SLOT(receiveSignalPinFromEngine()),Qt::QueuedConnection);
    connect(pDLLPinCode,SIGNAL(sendPinCodeToEngineAtm(int)),this,SLOT(receiveSignalFromDllPin(int)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendKorttiPinToRestApi(QString, QString)),pDLLRestAPI,SLOT(KorttiPinFromEngine(QString, QString)),Qt::QueuedConnection);
    connect(pDLLRestAPI,SIGNAL(sendWrongPinToEngineATM()),this,SLOT(receiveWrongPinFromDllRestApi()),Qt::QueuedConnection);
    connect(this,SIGNAL(sendWrongPinToDLLPinCode()),pDLLPinCode,SLOT(receiveWrongPinFromEngineATM()),Qt::QueuedConnection);
    connect(pDLLRestAPI,SIGNAL(sendCorrectPinToEngineATM()),this,SLOT(receiveCorrectPinFromDllRestApi()),Qt::QueuedConnection);
    connect(pDLLRestAPI,SIGNAL(sendIdFnameLnameToEngineATM(int, QString, QString)),this,SLOT(receiveIdFnameLnameFromDllRestApi(int, QString, QString)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendFnameLnameToValikko(QString, QString)),pValikko,SLOT(receiveFnameLnameFromEngineATM(QString, QString)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendClosePin()),pDLLPinCode,SLOT(receiveClosePin()),Qt::QueuedConnection);
    connect(pValikko,SIGNAL(SaldoMenu()),this,SLOT(receiveSaldoMenu()),Qt::QueuedConnection);
    connect(pDLLRestAPI,SIGNAL(sendBalanceToEngineATM(QString)),this,SLOT(receiveBalanceFromDllRestApi(QString)),Qt::QueuedConnection);
    connect(this,SIGNAL(requestBalance(int)),pDLLRestAPI,SLOT(requestBalanceFromATMEngine(int)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendBalanceToSaldo(QString)),psaldo,SLOT(receiveBalanceFromEngineATM(QString)),Qt::QueuedConnection);
    connect(pDLLRestAPI,SIGNAL(sendActions5FromRestApi(QByteArray)),this,SLOT(receiveActions5FromRestApi(QByteArray)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendActions5ToSaldo(QByteArray)),psaldo,SLOT(receiveActions5FromEngineATM(QByteArray)),Qt::QueuedConnection);
    connect(pValikko,SIGNAL(TilitapahtumatMenu()),this,SLOT(receiveTilitapahtumatMenu()),Qt::QueuedConnection);
    connect(this,SIGNAL(requestActions(int,int)),pDLLRestAPI,SLOT(requestActionsFromATMEngine(int,int)),Qt::QueuedConnection);
    connect(pDLLRestAPI,SIGNAL(sendActionsFromRestApi(QByteArray)),this,SLOT(receiveActionsFromRestApi(QByteArray)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendActionsToTilitapahtumat(QByteArray)),ptilitapahtumat,SLOT(receiveActionsFromEngineATM(QByteArray)),Qt::QueuedConnection);
    connect(ptilitapahtumat,SIGNAL(requestActionsFromTilitapahtumat(int)),this,SLOT(receiveTilitapahtumat(int)),Qt::QueuedConnection);
    connect(pDLLPinCode,SIGNAL(sendTimerResetFromDllPincode()),this,SLOT(receiveTimerReset()),Qt::QueuedConnection);
    connect(ptimerEventATM,SIGNAL(sendLogout()),this,SLOT(logout()),Qt::QueuedConnection);
    connect(this,SIGNAL(sendCleanVariablesToDllRestApi()),pDLLRestAPI,SLOT(receiveCleanVariablesFromEngineATM()),Qt::QueuedConnection);
    connect(this,SIGNAL(sendReStartToDllSerialPort()),pDLLSerialPort,SLOT(receiveReStartFromEngineAtm()),Qt::QueuedConnection);
    connect(this,SIGNAL(sendClosePinWindow()),pDLLPinCode,SLOT(receiveClosePinWindow()),Qt::QueuedConnection);
    connect(this,SIGNAL(sendCloseValikko()),pValikko,SLOT(receiveCloseValikko()),Qt::QueuedConnection);
    connect(pValikko,SIGNAL(logoutValikko()),this,SLOT(logout()),Qt::QueuedConnection);
    connect(this,SIGNAL(sendTimerStop()),ptimerEventATM,SLOT(receiveTimerStop()),Qt::QueuedConnection);
    connect(pDLLRestAPI,SIGNAL(sendLockedPinToEngineATM()),this,SLOT(receiveLockedPinFromDllRestApi()),Qt::QueuedConnection);
    connect(this,SIGNAL(sendLockedPinToDllPinCode()),pDLLPinCode,SLOT(receiveLockedPinFromEngineATM()),Qt::QueuedConnection);
    connect(this,SIGNAL(sendStartLockedPinTimer()),ptimerEventATM,SLOT(receiveStartLockedPinTimer()),Qt::QueuedConnection);
    connect(psaldo,SIGNAL(sendCloseFromSaldo()),this,SLOT(receiveCloseFromSaldo()),Qt::QueuedConnection);
    connect(this,SIGNAL(sendCloseSaldo()),psaldo,SLOT(receiveCloseSaldo()),Qt::QueuedConnection);
    connect(ptilitapahtumat,SIGNAL(sendCloseFromTilitapahtumat()),this,SLOT(receiveCloseFromTilitapahtumat()),Qt::QueuedConnection);
    connect(this,SIGNAL(sendCloseTilitapahtumat()),ptilitapahtumat,SLOT(receiveCloseTilitapahtumat()),Qt::QueuedConnection);
    connect(psaldo,SIGNAL(logoutSaldo()),this,SLOT(logout()),Qt::QueuedConnection);
    connect(ptilitapahtumat,SIGNAL(logoutTilitapahtumat()),this,SLOT(logout()),Qt::QueuedConnection);
    connect(ptilitapahtumat,SIGNAL(sendTimerResetFromTilitapahtumat()),this,SLOT(receiveTimerReset()),Qt::QueuedConnection);
    connect(ptilitapahtumat,SIGNAL(requestFutureActionsFromTilitapahtumat(int)),this,SLOT(receiveRequestFutureActionsFromTilitapahtumat(int)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendRequestFutureActionsFromEngineATM(int,int)),pDLLRestAPI,SLOT(receiveRequestFutureActionsFromEngineATM(int,int)),Qt::QueuedConnection);
    connect(pDLLRestAPI,SIGNAL(sendFutureActionsToEngineATM(QByteArray)),this,SLOT(receiveFutureActionsToEngineATM(QByteArray)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendFutureActionsToTilitapahtumat(QByteArray)),ptilitapahtumat,SLOT(receiveFutureActionsToTilitapahtumat(QByteArray)),Qt::QueuedConnection);
}

engineatm::~engineatm()
{
    delete ptimerEventATM;
    delete pDLLSerialPort;
    delete pDLLRestAPI;
    delete pDLLPinCode;
    delete pValikko;
    delete psaldo;
    delete ptilitapahtumat;
}

void engineatm::testfunction()
{
    emit sendStartToTimer();
    emit sendSignalToExeFromEngineRfid();
    pValikko->show();
    ptimerEventATM->resetMyTimer();
}

void engineatm::receiveSignalFromRfid(long long kortti2)
{
    emit sendStartToTimer();
    emit sendSignalToExeFromEngineRfid();
    kortti=kortti2;
    emit sendSignalPinToDLL();
    qDebug() << "signal from rfid";
}

void engineatm::receiveSignalfromNosto(QString amount)
{
    qDebug() << amount;
    emit sendSignalToDllRestApi(amount);
}

void engineatm::receiveSignalFromDllPin(int pinnumber)
{
    qDebug() << kortti << pinnumber;
    QString Qkortti = QString::number(kortti);
    QString Qpin = QString::number(pinnumber);
    emit sendKorttiPinToRestApi(Qkortti, Qpin);
}

void engineatm::receiveWrongPinFromDllRestApi()
{
    emit sendWrongPinToDLLPinCode();
}

void engineatm::receiveCorrectPinFromDllRestApi()
{
    emit sendClosePin();
    pValikko->show();
    ptimerEventATM->resetMyTimer();
//    pValikko->show();
//    delete pValikko;
//    pValikko = nullptr;
}

void engineatm::receiveIdFnameLnameFromDllRestApi(int id, QString fname, QString lname)
{
    qDebug() << "received id, fname, lname from dllrestapi";
    idAccount=id;
    emit sendFnameLnameToValikko(fname, lname);
}

void engineatm::receiveBalanceFromDllRestApi(QString balance)
{
    qDebug() << "balance from dllrestapi";
    emit sendBalanceToSaldo(balance);
}

void engineatm::receiveSaldoMenu()
{
    emit requestBalance(idAccount);
    pValikko -> hide();
    psaldo -> show();
    ptimerEventATM->resetMyTimer();
//    psaldo -> show();
//    delete psaldo;
//    psaldo = nullptr;
}

void engineatm::receiveActions5FromRestApi(QByteArray actions5)
{
    emit sendActions5ToSaldo(actions5);
}

void engineatm::receiveTilitapahtumatMenu()
{
    emit requestActions(idAccount,0);
    pValikko -> hide();
    ptilitapahtumat -> show();
    ptimerEventATM->resetMyTimer();
//    ptilitapahtumat -> show();
//    delete ptilitapahtumat;
//    ptilitapahtumat = nullptr;
}

void engineatm::receiveActionsFromRestApi(QByteArray actions10)
{
    emit sendActionsToTilitapahtumat(actions10);
}

void engineatm::receiveTilitapahtumat(int pagenumber)
{
    qDebug() << "Next saatu";
    emit requestActions(idAccount,pagenumber);
}

void engineatm::receiveTimerReset()
{
    ptimerEventATM->resetMyTimer();
}

void engineatm::logout()
{
    qDebug() << "logoutSlot";

    emit sendTimerStop();
    idAccount=0;
    kortti=0;
    emit sendClosePinWindow();
    emit sendCloseSaldo();
    emit sendCloseValikko();
    emit sendCloseTilitapahtumat();
    emit sendCleanVariablesToDllRestApi();
    emit sendReStartToDllSerialPort();
    emit sendShowToMainWindow();
}

void engineatm::receiveLockedPinFromDllRestApi()
{
    emit sendLockedPinToDllPinCode();
    emit sendStartLockedPinTimer();
}

void engineatm::receiveCloseFromSaldo()
{
    emit sendCloseSaldo();
    pValikko->show();
}

void engineatm::receiveCloseFromTilitapahtumat()
{
    emit sendCloseTilitapahtumat();
    pValikko->show();
}

void engineatm::receiveRequestFutureActionsFromTilitapahtumat(int pagenumber)
{
    emit sendRequestFutureActionsFromEngineATM(idAccount,pagenumber);
}

void engineatm::receiveFutureActionsToEngineATM(QByteArray futureActions10)
{
    emit sendFutureActionsToTilitapahtumat(futureActions10);
}

