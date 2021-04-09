#include "engineatm.h"

engineatm::engineatm(QObject *parent):QObject(parent)
{
    pDLLSerialPort = new DLLSerialPort;
    pDLLRestAPI = new DLLRestAPI;
//    connect(this,SIGNAL(sendSignalToRfid()),pDllrfid,SLOT(receiveSignalFromExe()),Qt::QueuedConnection);
    connect(pDLLSerialPort,SIGNAL(sendSignalToExeFromRfid()),this,SLOT(receiveSignalFromRfid()),Qt::QueuedConnection);
    connect(this,SIGNAL(sendSignalToDllRestApi(QString)),pDLLRestAPI,SLOT(SignalFromEngineNosto(QString)),Qt::QueuedConnection);
}

engineatm::~engineatm()
{
    delete pDLLSerialPort;
    delete pDLLRestAPI;
}

void engineatm::receiveSignalFromRfid()
{
    emit sendSignalToExeFromEngineRfid();
}

void engineatm::receiveSignalfromNosto(QString amount)
{
    qDebug() << amount;
    emit sendSignalToDllRestApi(amount);
}
