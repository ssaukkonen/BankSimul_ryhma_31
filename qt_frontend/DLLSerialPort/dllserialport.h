#ifndef DLLSERIALPORT_H
#define DLLSERIALPORT_H

#include "DLLSerialPort_global.h"
#include <QObject>
#include "enginerfid.h"

class DLLSERIALPORT_EXPORT DLLSerialPort :public QObject
{
    Q_OBJECT
public:
    DLLSerialPort(QObject * parent = nullptr);
    ~DLLSerialPort();

public slots:
    void receiveSignalFromEngine();
//    void signalReceivedFromCard();

signals:
    void sendSignalToExeFromRfid();
    void sendSignalToEngine();

private:
    enginerfid *penginerfid;
//    QSerialPort *pQSerialPort;
//    QSerialPortInfo *pQSerialPortInfo;
};

#endif // DLLSERIALPORT_H
