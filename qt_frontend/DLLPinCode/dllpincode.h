#ifndef DLLPINCODE_H
#define DLLPINCODE_H

#include "DLLPinCode_global.h"
#include <QObject>
#include "pindialog.h"
#include <QDebug>

class DLLPINCODE_EXPORT DLLPinCode : public QObject
{
    Q_OBJECT
public:
    DLLPinCode(QObject *parent = nullptr);
    ~DLLPinCode();

public slots:
    void receiveSignalPinFromEngine();
    void receiveSignalFromPinDialog(int);
    void receiveWrongPinFromEngineATM();
    void receiveClosePin();
    void receiveTimerResetFromPinDialog();
    void receiveClosePinWindow();

signals:
    void sendPinCodeToEngineAtm(int);
    void sendWrongPinToPinDialog();
    void sendClosePinDialog();
    void sendTimerResetFromDllPincode();

private:
    pindialog * ppindialog;
};

#endif // DLLPINCODE_H
