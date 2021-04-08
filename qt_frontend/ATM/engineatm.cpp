#include "engineatm.h"

engineatm::engineatm(QObject *parent):QObject(parent)
{
    pDLLSerialPort = new DLLSerialPort;
//    connect(this,SIGNAL(sendSignalToRfid()),pDllrfid,SLOT(receiveSignalFromExe()),Qt::QueuedConnection);
    connect(pDLLSerialPort,SIGNAL(sendSignalToExeFromRfid()),this,SLOT(receiveSignalFromRfid()),Qt::QueuedConnection);
//  connect(pDllrfid,SIGNAL(),this,SLOT(),Qt::QueuedConnection);
}

engineatm::~engineatm()
{
    delete pDLLSerialPort;
}

void engineatm::receiveSignalFromRfid()
{
    emit sendSignalToExeFromEngineRfid();
}
