#include "enginerfid.h"

enginerfid::enginerfid(QObject *parent):QObject(parent)
{
    pQSerialPortInfo = new QSerialPortInfo;
    pQSerialPort = new QSerialPort;
    connect(pQSerialPort,SIGNAL(readyRead()),this,SLOT(signalReceivedFromCard()),Qt::QueuedConnection);

    pQSerialPort->setPortName("com3");
    qDebug() << pQSerialPort->portName();
    pQSerialPort->setBaudRate(9600);
    pQSerialPort->setDataBits(QSerialPort::Data8);
    pQSerialPort->setParity(QSerialPort::NoParity);
    pQSerialPort->setStopBits(QSerialPort::OneStop);
    pQSerialPort->setFlowControl(QSerialPort::HardwareControl);
    pQSerialPort->open(QIODevice::ReadWrite);
}

enginerfid::~enginerfid()
{
    delete pQSerialPort;
    delete pQSerialPortInfo;
}

void enginerfid::signalReceivedFromCard()
{
    pQSerialPort->close();
    emit sendSignalToInterface();
}
