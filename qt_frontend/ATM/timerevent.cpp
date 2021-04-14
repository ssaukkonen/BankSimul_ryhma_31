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
    timer->stop();
    qDebug() << "exit";
}

void timerEvent::receiveStartFromEngineATM()
{
    timer->start(5000);
    qDebug() << "timer start";
}

void timerEvent::resetMyTimer()
{
    timer->stop();
    qDebug() << "timer reset";
    timer->start(5000);
}
