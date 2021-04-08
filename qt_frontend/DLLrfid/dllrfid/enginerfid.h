#ifndef ENGINERFID_H
#define ENGINERFID_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QByteArray>

class enginerfid : public QObject
{
    Q_OBJECT
public:
    enginerfid(QObject *parent = nullptr);
    ~enginerfid();

public slots:
    void signalReceivedFromCard();

signals:
    void sendSignalToInterface();

private:
    QSerialPort *pQSerialPort;
    QSerialPortInfo *pQSerialPortInfo;
};

#endif // ENGINERFID_H
