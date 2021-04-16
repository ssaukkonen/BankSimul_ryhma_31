#ifndef PINDIALOG_H
#define PINDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QKeyEvent>
#include <QMouseEvent>

namespace Ui {
class pindialog;
}

class pindialog : public QDialog
{
    Q_OBJECT

public:
    explicit pindialog(QWidget *parent = nullptr);
    ~pindialog();

private slots:
    void on_pushButtonOK_clicked();

    void on_lineEditPin_textEdited(const QString &arg1);

public slots:
    void receiveWrongPinFromDLLPinCode();
    void receiveClosePinDialog();

signals:
    void sendSignalToDllPinInterface(int);
    void sendTimerResetToDllPinCode();

private:
    Ui::pindialog *ui;

protected:
    void keyPressEvent(QKeyEvent *eventKey);
    void mousePressEvent(QMouseEvent *eventMouse);
};

#endif // PINDIALOG_H
