#ifndef NOSTO_H
#define NOSTO_H

#include <QDialog>


namespace Ui {
class nosto;
}

class nosto : public QDialog
{
    Q_OBJECT

public:
    explicit nosto(QWidget *parent = nullptr);
    ~nosto();
    void setNostoDefaults();

private slots:
    void on_button20_clicked();

    void on_button40_clicked();

    void on_button60_clicked();

    void on_button100_clicked();

    void on_button200_clicked();

    void on_button500_clicked();

    void on_buttonSaldo_clicked();

    void on_buttonBack_clicked();

    void on_buttonLogOut_clicked();


public slots:
    void receiveNostoNotWorkingFromEngine();
    void receiveNostoWorkingFromEngine();
    void receiveCloseNosto();
    void receiveBalanceToNostoFromEngineATM(QString);

private:
    Ui::nosto *ui;
    QString amount;


protected:
    void mousePressEvent(QMouseEvent *eventMouse);

signals:
    void SignalToEngineFromNosto(QString);
    void logoutNosto();
    void sendCloseFromNosto();
    void sendSaldoKyselyToEngine();
    void sendTimerResetToEngineFromNosto();
};

#endif // NOSTO_H
