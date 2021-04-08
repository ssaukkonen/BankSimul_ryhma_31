#ifndef DLLRFID_H
#define DLLRFID_H

#include "dllrfid_global.h"
#include <QObject>
#include "enginerfid.h"
//#include <QtSerialPort/QSerialPort>
//#include <QtSerialPort/QSerialPortInfo>
//#include <QDebug>
//#include <QByteArray>


class DLLRFID_EXPORT Dllrfid : public QObject
{
    Q_OBJECT
public:
    Dllrfid(QObject * parent = nullptr);
    ~Dllrfid();

public slots:
    void receiveSignalFromEngine();
//    void signalReceivedFromCard();

signals:
    void sendSignalToExeFromRfid();
    void sendSignalToEngine();

private:
    enginerfid *pengineclass;
//    QSerialPort *pQSerialPort;
//    QSerialPortInfo *pQSerialPortInfo;

};

#endif // DLLRFID_H
