#ifndef TIMEREVENT_H
#define TIMEREVENT_H

#include <QObject>
#include <QDebug>
#include <QTimer>
//#include <QKeyEvent>
//#include <QMouseEvent>
#include <QEvent>

class timerEvent : public QObject
{
    Q_OBJECT
public:
    timerEvent();
    ~timerEvent();
    void resetMyTimer();

public slots:
    void timerslot();
    void receiveStartFromEngineATM();
    void receiveTimerStop();

signals:
    void sendLogout();

protected:
//    bool eventFilter(QObject *obj, QEvent *ev)
//    {
//      if(ev->type() == QEvent::KeyPress ||
//         ev->type() == QEvent::MouseButtonPress){
//           // now reset your timer, for example
//           resetMyTimer();
//      }
//      else return QObject::eventFilter(obj, ev);
//      return true;
//    }

private:
    QTimer *timer;
};

#endif // TIMEREVENT_H
