#ifndef ENGINEATM_H
#define ENGINEATM_H

#include <QObject>
#include <QWidget>
#include "dllserialport.h"
#include "dllrestapi.h"
#include <QDebug>

class engineatm : public QObject
{
    Q_OBJECT
public:
    engineatm(QObject *parent = nullptr);
    ~engineatm();

signals:
    void sendSignalToRfid();
    void sendSignalToExeFromEngineRfid();
//    void sendSignalToNosto();
    void sendSignalToDllRestApi(QString);

public slots:
    void receiveSignalFromRfid();
    void receiveSignalfromNosto(QString);

private:
    DLLSerialPort * pDLLSerialPort;
    DLLRestAPI * pDLLRestAPI;
};

#endif // ENGINEATM_H
