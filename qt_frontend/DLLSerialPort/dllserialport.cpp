#include "dllserialport.h"

DLLSerialPort::DLLSerialPort(QObject *parent):QObject(parent)
{
    penginerfid = new enginerfid;
    connect(penginerfid,SIGNAL(sendSignalToInterface(long long)),this,SLOT(receiveSignalFromEngine(long long)),Qt::QueuedConnection);
}

DLLSerialPort::~DLLSerialPort()
{
    delete penginerfid;
}

void DLLSerialPort::receiveSignalFromEngine(long long kortti)
{
    emit sendSignalToExeFromRfid(kortti);
}
