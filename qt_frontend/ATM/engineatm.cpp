#include "engineatm.h"

engineatm::engineatm(QObject *parent):QObject(parent)
{
    pDLLSerialPort = new DLLSerialPort;
    pDLLRestAPI = new DLLRestAPI;
    pDLLPinCode = new DLLPinCode;
    pValikko = new Valikko;
    psaldo = new saldo;
//    connect(this,SIGNAL(sendSignalToRfid()),pDllrfid,SLOT(receiveSignalFromExe()),Qt::QueuedConnection);
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
    connect(pDLLRestAPI,SIGNAL(sendBalanceToEngineATM(QString)),this,SLOT(receiveBalanceDllRestApi(QString)),Qt::QueuedConnection);
    connect(this,SIGNAL(requestBalance(int)),pDLLRestAPI,SLOT(requestBalanceFromATMEngine(int)),Qt::QueuedConnection);
}

engineatm::~engineatm()
{
    delete pDLLSerialPort;
    delete pDLLRestAPI;
    delete pDLLPinCode;
}

void engineatm::testfunction()
{
    pValikko->exec();
    pValikko->show();
    delete pValikko;
    pValikko = nullptr;
}

void engineatm::receiveSignalFromRfid(long long kortti2)
{
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
    pValikko->exec();
    pValikko->show();
    delete pValikko;
    pValikko = nullptr;
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
    psaldo -> exec();
    psaldo -> show();
    delete psaldo;
    psaldo = nullptr;
}
