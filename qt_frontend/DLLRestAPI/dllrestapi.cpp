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
    connect(pengineretsapi,SIGNAL(sendActions5ToDllRestApi(QString)),this,SLOT(receiveActions5FromEngineRestApi(QString)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendActionsRequestToEngineRestApi(int)),pengineretsapi,SLOT(receiveActionsRequestToEngineRestApi(int)),Qt::QueuedConnection);
    connect(pengineretsapi,SIGNAL(sendActionsToDllRestApi(QString)),this,SLOT(receiveActionsToDllRestApi(QString)),Qt::QueuedConnection);
    connect(pengineretsapi,SIGNAL(NextTilitapFromEngineATM(int)),this,SLOT(receiveNextTilitapFromEngineATM(int)),Qt::QueuedConnection);
    connect(pengineretsapi,SIGNAL(PreviousTilitapFromEngineATM(int)),this,SLOT(receivePreviousTilitapFromEngineATM(int)),Qt::QueuedConnection);
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

void DLLRestAPI::receiveActions5FromEngineRestApi(QString actions5)
{
    emit sendActions5FromRestApi(actions5);
}

void DLLRestAPI::requestActionsFromATMEngine(int id) //tilitapahtumat
{
    emit sendActionsRequestToEngineRestApi(id);
}

void DLLRestAPI::receiveActionsToDllRestApi(QString actions10)
{
    emit sendActionsFromRestApi(actions10);
}

void DLLRestAPI::receiveNextTilitapFromEngineATM(int id)
{
    emit sendNextTilitapFromRestApi(id);
}

void DLLRestAPI::receivePreviousTilitapFromEngineATM(int id)
{
    emit sendPreviousTilitapFromRestApi(id);
}
