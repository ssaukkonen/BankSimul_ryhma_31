#ifndef ENGINEATM_H
#define ENGINEATM_H

#include <QObject>
#include <QWidget>
#include "dllserialport.h"

class engineatm : public QObject
{
    Q_OBJECT
public:
    engineatm(QObject *parent = nullptr);
    ~engineatm();

signals:
    void sendSignalToRfid();
    void sendSignalToExeFromEngineRfid();

public slots:
    void receiveSignalFromRfid();

private:
    DLLSerialPort * pDLLSerialPort;

};

#endif // ENGINEATM_H
