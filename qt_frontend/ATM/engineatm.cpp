#include "engineatm.h"

engineatm::engineatm(QObject *parent):QObject(parent)
{
    pDLLSerialPort = new DLLSerialPort;
    pDLLRestAPI = new DLLRestAPI;
    ppinengine = new DLLPinCode;
//    connect(this,SIGNAL(sendSignalToRfid()),pDllrfid,SLOT(receiveSignalFromExe()),Qt::QueuedConnection);
    connect(pDLLSerialPort,SIGNAL(sendSignalToExeFromRfid(long long)),this,SLOT(receiveSignalFromRfid(long long)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendSignalToDllRestApi(QString)),pDLLRestAPI,SLOT(SignalFromEngineNosto(QString)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendSignalPinToDLL()),ppinengine,SLOT(receiveSignalPinFromEngine()),Qt::QueuedConnection);
    connect(ppinengine,SIGNAL(sendPinCodeToEngineAtm(int)),this,SLOT(receiveSignalFromDllPin(int)),Qt::QueuedConnection);
}

engineatm::~engineatm()
{
    delete pDLLSerialPort;
    delete pDLLRestAPI;
    delete ppinengine;
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
}
