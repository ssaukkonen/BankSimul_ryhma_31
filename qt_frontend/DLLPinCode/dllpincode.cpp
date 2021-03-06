#include "dllpincode.h"

DLLPinCode::DLLPinCode(QObject *parent):QObject(parent)
{
    ppindialog = new pindialog;
    connect(ppindialog,SIGNAL(sendSignalToDllPinInterface(int)),this,SLOT(receiveSignalFromPinDialog(int)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendWrongPinToPinDialog()),ppindialog,SLOT(receiveWrongPinFromDLLPinCode()),Qt::QueuedConnection);
    connect(this,SIGNAL(sendClosePinDialog()),ppindialog,SLOT(receiveClosePinDialog()),Qt::QueuedConnection);
    connect(ppindialog,SIGNAL(sendTimerResetToDllPinCode()),this,SLOT(receiveTimerResetFromPinDialog()),Qt::QueuedConnection);
    connect(this,SIGNAL(sendLockedPinFromDllPinCode()),ppindialog,SLOT(receiveLockedPinFromDllPinCode()),Qt::QueuedConnection);
}

DLLPinCode::~DLLPinCode()
{
    delete ppindialog;
    ppindialog = nullptr;
}

void DLLPinCode::receiveSignalPinFromEngine()
{
//    ppindialog->startTimerPin();
    ppindialog->exec();
//    ppindialog->show();
//    delete ppindialog;
//    ppindialog = nullptr;
}

void DLLPinCode::receiveSignalFromPinDialog(int pinnumber)
{
    qDebug() << pinnumber;
    emit sendPinCodeToEngineAtm(pinnumber);
}

void DLLPinCode::receiveWrongPinFromEngineATM()
{
    emit sendWrongPinToPinDialog();
}

void DLLPinCode::receiveClosePin()
{
    emit sendClosePinDialog();
}

void DLLPinCode::receiveTimerResetFromPinDialog()
{
    emit sendTimerResetFromDllPincode();
}

void DLLPinCode::receiveClosePinWindow()
{
    emit sendClosePinDialog();;
}

void DLLPinCode::receiveLockedPinFromEngineATM()
{
    emit sendLockedPinFromDllPinCode();
}
