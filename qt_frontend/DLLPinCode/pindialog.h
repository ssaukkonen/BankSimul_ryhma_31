#ifndef PINDIALOG_H
#define PINDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QTimer>

namespace Ui {
class pindialog;
}

class pindialog : public QDialog
{
    Q_OBJECT

public:
    explicit pindialog(QWidget *parent = nullptr);
    ~pindialog();
//    void startTimerPin();

private slots:
    void on_pushButtonOK_clicked();

public slots:
    void receiveWrongPinFromDLLPinCode();
    void receiveClosePinDialog();
//    void timerslotPin();

signals:
    void sendSignalToDllPinInterface(int);

private:
    Ui::pindialog *ui;
//    QTimer * timerPin;

//protected:
//    void keyPressEvent(QKeyEvent *eventKey);
//    void mousePressEvent(QMouseEvent *eventMouse);
};

#endif // PINDIALOG_H
