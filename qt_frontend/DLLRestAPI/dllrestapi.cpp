#include "dllrestapi.h"

DLLRestAPI::DLLRestAPI(QObject *parent):QObject(parent)
{
    pengineretsapi = new enginerestapi;
    connect(this,SIGNAL(SignalToEngineRestApi(QString)),pengineretsapi,SLOT(SignalFromDllRestApi(QString)),Qt::QueuedConnection);
}

DLLRestAPI::~DLLRestAPI()
{
    delete pengineretsapi;
}

void DLLRestAPI::SignalFromEngineNosto(QString amount)
{
    qDebug() << amount;
    qDebug() << "DLL";
    emit SignalToEngineRestApi(amount);
}
