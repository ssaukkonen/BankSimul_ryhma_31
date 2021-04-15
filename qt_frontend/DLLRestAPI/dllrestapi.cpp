#include "dllrestapi.h"

DLLRestAPI::DLLRestAPI(QObject *parent):QObject(parent)
{
    pengineretsapi = new enginerestapi;
    connect(this,SIGNAL(SignalToEngineRestApi(QString)),pengineretsapi,SLOT(SignalFromDllRestApi(QString)),Qt::QueuedConnection);
    connect(this,SIGNAL(KorttiPinToRestApiEngine(QString, QString)),pengineretsapi,SLOT(KorttiPinFromEngine(QString, QString)),Qt::QueuedConnection);
    connect(pengineretsapi,SIGNAL(sendWrongPinToDllRestApi()),this,SLOT(receiveWrongPinFromEngineRestApi()),Qt::QueuedConnection);
    connect(pengineretsapi,SIGNAL(sendCorrectPinToDllRestApi()),this,SLOT(receiveCorrectPinFromEngineRestApi()),Qt::QueuedConnection);
    connect(pengineretsapi,SIGNAL(sendIdFnameLnameToDllRestApi(int, QString, QString)),this,SLOT(receiveIdFnameLnameFromEngineRestApi(int, QString, QString)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendBalanceRequestToEngine(int)),pengineretsapi,SLOT(BalanceFromEngine(int)));
    connect(pengineretsapi,SIGNAL(sendBalanceToDllRestApi(QString)),this,SLOT(receiveBalanceFromEngineRestApi(QString)),Qt::QueuedConnection);
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

void DLLRestAPI::KorttiPinFromEngine(QString Qkortti, QString Qpin)
{
    emit KorttiPinToRestApiEngine(Qkortti, Qpin);
}

void DLLRestAPI::receiveWrongPinFromEngineRestApi()
{
    emit sendWrongPinToEngineATM();
}

void DLLRestAPI::receiveCorrectPinFromEngineRestApi()
{
    emit sendCorrectPinToEngineATM();
}

void DLLRestAPI::receiveIdFnameLnameFromEngineRestApi(int idAccount, QString fname, QString lname)
{
    emit sendIdFnameLnameToEngineATM(idAccount, fname, lname);
}

void DLLRestAPI::receiveBalanceFromEngineRestApi(QString balance)
{
    emit sendBalanceToEngineATM(balance);
}

void DLLRestAPI::requestBalanceFromATMEngine(int id)
{
    emit sendBalanceRequestToEngine(id);
}
