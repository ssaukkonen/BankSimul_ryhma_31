#include "dllpincode.h"

DLLPinCode::DLLPinCode(QObject *parent):QObject(parent)
{
    ppindialog = new pindialog;
    connect(ppindialog,SIGNAL(sendSignalToDllPinInterface(int)),this,SLOT(receiveSignalFromPinDialog(int)),Qt::QueuedConnection);
}

DLLPinCode::~DLLPinCode()
{
    delete ppindialog;
    ppindialog = nullptr;
}

void DLLPinCode::receiveSignalPinFromEngine()
{
    ppindialog->exec();
    ppindialog->show();
    delete ppindialog;
    ppindialog = nullptr;
}

void DLLPinCode::receiveSignalFromPinDialog(int pinnumber)
{
    qDebug() << pinnumber;
    emit sendPinCodeToEngineAtm(pinnumber);
}
