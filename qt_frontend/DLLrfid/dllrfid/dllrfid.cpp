#include "dllrfid.h"

Dllrfid::Dllrfid(QObject * parent):QObject(parent)
{
    pengineclass = new enginerfid;
//    connect(this,SIGNAL(sendSignalToEngine()),pengine,SLOT(receiveSignalFromInterface()),Qt::QueuedConnection);
    connect(pengineclass,SIGNAL(sendSignalToInterface()),this,SLOT(receiveSignalFromEngine()),Qt::QueuedConnection);
//    pQSerialPortInfo = new QSerialPortInfo;
//    pQSerialPort = new QSerialPort;
//    connect(pQSerialPort,SIGNAL(readyRead()),this,SLOT(signalReceivedFromCard()),Qt::QueuedConnection);

//    pQSerialPort->setPortName("com3");
//    qDebug() << pQSerialPort->portName();
//    pQSerialPort->setBaudRate(9600);
//    pQSerialPort->setDataBits(QSerialPort::Data8);
//    pQSerialPort->setParity(QSerialPort::NoParity);
//    pQSerialPort->setStopBits(QSerialPort::OneStop);
//    pQSerialPort->setFlowControl(QSerialPort::HardwareControl);
//    pQSerialPort->open(QIODevice::ReadWrite);
}

Dllrfid::~Dllrfid()
{
    delete pengineclass;
//    pQSerialPort->close();
//    delete pQSerialPort;
    //    delete pQSerialPortInfo;
}

void Dllrfid::receiveSignalFromEngine()
{
    emit sendSignalToExeFromRfid();
}

//void Dllrfid::signalReceivedFromCard()
//{
//    QByteArray koodi = pQSerialPort->readAll();
//    koodi.remove(0,3);
//    qDebug() << koodi;
//    koodi.remove(10,10);
//    qDebug() << koodi;
//    bool ok;
//    long long luku = koodi.toLongLong(&ok, 16);
//    pQSerialPort->close();
//    emit sendSignalToExeFromRfid();
//}
