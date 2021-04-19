#ifndef NOSTO_H
#define NOSTO_H

#include <QDialog>
#include <QDebug>
//#include "engineatm.h"

namespace Ui {
class nosto;
}

class nosto : public QDialog
{
    Q_OBJECT

public:
    explicit nosto(QWidget *parent = nullptr);
    ~nosto();

private slots:
    void on_button20_clicked();

    void on_button40_clicked();

    void on_button60_clicked();

    void on_button100_clicked();

    void on_button200_clicked();

    void on_button500_clicked();

    void on_buttonSaldo_clicked();

    void on_buttonMainMenu_clicked();

    void on_buttonLogOut_clicked();

public slots:
    void receiveNostoNotWorkingFromEngine();
    void receiveNostoWorkingFromEngine();

private:
    Ui::nosto *ui;
    QString amount;


signals:
    void SignalToEngineFromNosto(QString);
    void logoutNosto();
};

#endif // NOSTO_H
