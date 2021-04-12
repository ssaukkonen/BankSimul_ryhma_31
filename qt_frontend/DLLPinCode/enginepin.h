#ifndef ENGINEPIN_H
#define ENGINEPIN_H

#include <QObject>

class enginePin : public QObject
{
    Q_OBJECT
public:
    enginePin(QObject *parent = nullptr);
    ~enginePin();
};

#endif // ENGINEPIN_H
