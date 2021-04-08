#include "engineatm.h"

engineatm::engineatm(QObject *parent):QObject(parent)
{
    pDllrfid = new Dllrfid;
//    connect(this,SIGNAL(sendSignalToRfid()),pDllrfid,SLOT(receiveSignalFromExe()),Qt::QueuedConnection);
    connect(pDllrfid,SIGNAL(sendSignalToExeFromRfid()),this,SLOT(receiveSignalFromRfid()),Qt::QueuedConnection);
//  connect(pDllrfid,SIGNAL(),this,SLOT(),Qt::QueuedConnection);
}

engineatm::~engineatm()
{
    delete pDllrfid;
}

void engineatm::receiveSignalFromRfid()
{
    emit sendSignalToExeFromEngineRfid();
}
