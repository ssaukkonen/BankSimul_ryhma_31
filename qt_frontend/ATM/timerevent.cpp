#include "timerevent.h"

timerEvent::timerEvent()
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(timerslot()));
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
    timer->start(5000);
    qDebug() << "timer start";
}

void timerEvent::receiveTimerStop()
{
    qDebug() << "receiveTimerStop";
    timer->stop();
}

void timerEvent::resetMyTimer()
{
    timer->stop();
    qDebug() << "timer reset";
    timer->start(5000);
}
