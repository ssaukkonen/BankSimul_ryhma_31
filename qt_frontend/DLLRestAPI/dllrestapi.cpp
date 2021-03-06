#include "dllrestapi.h"

DLLRestAPI::DLLRestAPI(QObject *parent):QObject(parent)
{
    pengineretsapi = new enginerestapi;
    connect(this,SIGNAL(SignalToEngineRestApi(QString)),pengineretsapi,SLOT(SignalFromDllRestApi(QString)),Qt::QueuedConnection);
    connect(this,SIGNAL(KorttiPinToRestApiEngine(QString, QString)),pengineretsapi,SLOT(KorttiPinFromEngine(QString, QString)),Qt::QueuedConnection);
    connect(pengineretsapi,SIGNAL(sendWrongPinToDllRestApi()),this,SLOT(receiveWrongPinFromEngineRestApi()),Qt::QueuedConnection);
    connect(pengineretsapi,SIGNAL(sendCorrectPinToDllRestApi()),this,SLOT(receiveCorrectPinFromEngineRestApi()),Qt::QueuedConnection);
    connect(pengineretsapi,SIGNAL(sendIdFnameLnameToDllRestApi(int, QString, QString, QString)),this,SLOT(receiveIdFnameLnameFromEngineRestApi(int, QString, QString, QString)),Qt::QueuedConnection);

    connect(pengineretsapi,SIGNAL(sendNostoNotWorking()),this,SLOT(receiveNostoNotWorking()),Qt::QueuedConnection);
    connect(pengineretsapi,SIGNAL(sendNostoWorking()),this,SLOT(receiveNostoWorking()),Qt::QueuedConnection);

    connect(this,SIGNAL(sendBalanceRequestToEngine(int)),pengineretsapi,SLOT(BalanceFromEngine(int)));
    connect(pengineretsapi,SIGNAL(sendBalanceToDllRestApi(QString)),this,SLOT(receiveBalanceFromEngineRestApi(QString)),Qt::QueuedConnection);
    connect(pengineretsapi,SIGNAL(sendActions5ToDllRestApi(QByteArray)),this,SLOT(receiveActions5FromEngineRestApi(QByteArray)),Qt::QueuedConnection);
    connect(this,SIGNAL(sendActionsRequestToEngineRestApi(int,int)),pengineretsapi,SLOT(receiveActionsRequestToEngineRestApi(int,int)),Qt::QueuedConnection);
    connect(pengineretsapi,SIGNAL(sendActionsToDllRestApi(QByteArray)),this,SLOT(receiveActionsToDllRestApi(QByteArray)),Qt::QueuedConnection);
    connect(pengineretsapi,SIGNAL(sendLockedPinToDllRestApi()),this,SLOT(receiveLockedPinFromEngineRestApi()),Qt::QueuedConnection);

    connect(this,SIGNAL(sendMoneyTodayFromDllRestApi(int, QString, QString, QString, QString, QString)),pengineretsapi,SLOT(receiveMoneyTodayFromDllRestApi(int, QString, QString, QString, QString, QString)),Qt::QueuedConnection);
    connect(pengineretsapi,SIGNAL(sendMoneyActionResultFromEngineRestApi(QString)),this,SLOT(receiveMoneyActionResultFromEngineRestApi(QString)),Qt::QueuedConnection);

    connect(this,SIGNAL(sendRequestFutureActionsFromRestApi(int,int)),pengineretsapi,SLOT(receiveRequestFutureActionsFromRestApi(int,int)),Qt::QueuedConnection);
    connect(pengineretsapi,SIGNAL(sendFutureActionsToDllRestApi(QByteArray)),this,SLOT(receiveFutureActionsToDllRestApi(QByteArray)),Qt::QueuedConnection);

    connect(this,SIGNAL(sendMoneyFutureFromDllRestApi(int, QString, QString, QString, QString, QString)),pengineretsapi,SLOT(receiveMoneyFutureFromDllRestApi(int, QString, QString, QString, QString, QString)),Qt::QueuedConnection);
    connect(pengineretsapi,SIGNAL(sendFutureActionResultFromEngineRestApi(QString)),this,SLOT(receiveFutureActionResultFromEngineRestApi(QString)),Qt::QueuedConnection);
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

void DLLRestAPI::receiveIdFnameLnameFromEngineRestApi(int idAccount, QString fname, QString lname, QString accnumber)
{
    emit sendIdFnameLnameToEngineATM(idAccount, fname, lname, accnumber);
}


void DLLRestAPI::receiveBalanceFromEngineRestApi(QString balance)
{
    emit sendBalanceToEngineATM(balance);
}

void DLLRestAPI::requestBalanceFromATMEngine(int id)
{
    emit sendBalanceRequestToEngine(id);
}

void DLLRestAPI::receiveActions5FromEngineRestApi(QByteArray actions5)
{
    emit sendActions5FromRestApi(actions5);
}

void DLLRestAPI::requestActionsFromATMEngine(int id, int pagenumber) //tilitapahtumat
{
    emit sendActionsRequestToEngineRestApi(id, pagenumber);
}

void DLLRestAPI::receiveActionsToDllRestApi(QByteArray actions10)
{
    emit sendActionsFromRestApi(actions10);
}

void DLLRestAPI::receiveCleanVariablesFromEngineATM()
{
    pengineretsapi->cleanVariablesEngineRestApi();
}

void DLLRestAPI::receiveLockedPinFromEngineRestApi()
{
    emit sendLockedPinToEngineATM();
}
void DLLRestAPI::receiveNostoNotWorking()
{
    emit sendNostoNotWorkingToEngineATM();
}

void DLLRestAPI::receiveNostoWorking()
{
    emit sendNostoWorkingToEngineATM();
}


void DLLRestAPI::receiveMoneyTodayFromEngine(int idaccount, QString summa, QString viite, QString viesti, QString tilinumero, QString date)
{
    emit sendMoneyTodayFromDllRestApi(idaccount, summa, viite, viesti, tilinumero, date);
}

void DLLRestAPI::receiveMoneyActionResultFromEngineRestApi(QString response_data)
{
    emit sendMoneyActionResultFromDllRestApi(response_data);
}
void DLLRestAPI::receiveRequestFutureActionsFromEngineATM(int id, int pagenumber) //tulevat tapahtumat
{
    emit sendRequestFutureActionsFromRestApi(id, pagenumber);
}

void DLLRestAPI::receiveFutureActionsToDllRestApi(QByteArray futureActions10)
{
    emit sendFutureActionsToEngineATM(futureActions10);

}

void DLLRestAPI::receiveMoneyFutureFromEngine(int idaccount, QString summa, QString viite, QString viesti, QString tilinumero, QString date)
{
    emit sendMoneyFutureFromDllRestApi(idaccount, summa, viite, viesti, tilinumero, date);
}

void DLLRestAPI::receiveFutureActionResultFromEngineRestApi(QString response_data)
{
    emit sendFutureActionResultFromDllRestApi(response_data);
}

