#ifndef TIMEREVENT_H
#define TIMEREVENT_H

#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QEvent>

class timerEvent : public QObject
{
    Q_OBJECT
public:
    timerEvent();
    ~timerEvent();

public slots:
    void timerslot();
    void receiveStartFromEngineATM();

protected:
    bool eventFilter(QObject *obj, QEvent *ev)
    {
      if(ev->KeyPress ||
         ev->MouseButtonPress){
           // now reset your timer, for example
           resetMyTimer();
      }
      else return QObject::eventFilter(obj, ev);
      return true;
    }

private:
    QTimer *timer;
    void resetMyTimer();
};

#endif // TIMEREVENT_H
