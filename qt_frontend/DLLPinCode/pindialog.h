#ifndef PINDIALOG_H
#define PINDIALOG_H

#include <QDialog>
#include <QDebug>

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

public slots:
    void receiveWrongPinFromDLLPinCode();
    void receiveClosePinDialog();

signals:
    void sendSignalToDllPinInterface(int);

private:
    Ui::pindialog *ui;
};

#endif // PINDIALOG_H
