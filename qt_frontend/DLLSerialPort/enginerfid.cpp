#include "enginerfid.h"

enginerfid::enginerfid(QObject *parent):QObject(parent)
{
    pQSerialPortInfo = new QSerialPortInfo;
    pQSerialPort = new QSerialPort;
    connect(pQSerialPort,SIGNAL(readyRead()),this,SLOT(signalReceivedFromCard()),Qt::QueuedConnection);

    pQSerialPort->setPortName("com3");
//    qDebug() << pQSerialPort->portName();
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

void enginerfid::restartRfid()
{
    pQSerialPort->open(QIODevice::ReadWrite);
}

void enginerfid::signalReceivedFromCard()
{
    QByteArray koodi = pQSerialPort->readAll();
    koodi.remove(0,3);
    qDebug() << koodi;
    koodi.remove(10,10);
    qDebug() << koodi;
    bool ok;
    long long kortti = koodi.toLongLong(&ok, 16);
    pQSerialPort->close();
    emit sendSignalToInterface(kortti);
}
