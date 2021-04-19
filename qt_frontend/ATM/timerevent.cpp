#include "timerevent.h"

timerEvent::timerEvent()
{
    timer = new QTimer(this);
    timer2 = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(timerslot()));
    connect(timer2, SIGNAL(timeout()),this,SLOT(timerslot()));
}

timerEvent::~timerEvent()
{
    delete timer;
}

void timerEvent::timerslot()
{
    qDebug() << "timerslot";
    emit sendLogout();
}

void timerEvent::receiveStartFromEngineATM()
{
    timer->start(10000);
    qDebug() << "timer start";
}

void timerEvent::receiveTimerStop()
{
    qDebug() << "receiveTimerStop";
    timer2->stop();
    timer->stop();
}

void timerEvent::receiveStartLockedPinTimer()
{
    timer2->start(5000);
}

void timerEvent::resetMyTimer()
{
    timer->stop();
    qDebug() << "timer reset";
    timer->start(10000);
}
