#include "engineatm.h"

engineatm::engineatm(QObject *parent):QObject(parent)
{
    pDLLSerialPort = new DLLSerialPort;
    pDLLRestAPI = new DLLRestAPI;
    ppinengine = new pin;
//    connect(this,SIGNAL(sendSignalToRfid()),pDllrfid,SLOT(receiveSignalFromExe()),Qt::QueuedConnection);
    connect(pDLLSerialPort,SIGNAL(sendSignalToExeFromRfid(long long)),this,SLOT(receiveSignalFromRfid(long long)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendSignalToDllRestApi(QString)),pDLLRestAPI,SLOT(SignalFromEngineNosto(QString)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendKorttiToPin(long long)),ppinengine,SLOT(receiveKorttiFromEngine(long long)),Qt::QueuedConnection);
}

engineatm::~engineatm()
{
    delete pDLLSerialPort;
    delete pDLLRestAPI;
}

void engineatm::receiveSignalFromRfid(long long kortti)
{
    emit sendSignalToExeFromEngineRfid();
    emit sendKorttiToPin(kortti);
}

void engineatm::receiveSignalfromNosto(QString amount)
{
    qDebug() << amount;
    emit sendSignalToDllRestApi(amount);
}
