#include "dllserialport.h"

DLLSerialPort::DLLSerialPort(QObject *parent):QObject(parent)
{
    penginerfid = new enginerfid;
    connect(penginerfid,SIGNAL(sendSignalToInterface()),this,SLOT(receiveSignalFromEngine()),Qt::QueuedConnection);
}

DLLSerialPort::~DLLSerialPort()
{
    delete penginerfid;
}

void DLLSerialPort::receiveSignalFromEngine()
{
    emit sendSignalToExeFromRfid();
}
