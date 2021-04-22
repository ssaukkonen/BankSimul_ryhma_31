#ifndef TILISIIRTO_H
#define TILISIIRTO_H

#include <QDialog>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QDebug>

namespace Ui {
class tilisiirto;
}

class tilisiirto : public QDialog
{
    Q_OBJECT

public:
    explicit tilisiirto(QWidget *parent = nullptr);
    ~tilisiirto();
    void setDefaults();

private slots:

    void on_lineEditTilinumero_textEdited(const QString &arg1);

    void on_lineEditSumma_textEdited(const QString &arg1);

    void on_lineEditViite_textEdited(const QString &arg1);

    void on_lineEditViesti_textEdited(const QString &arg1);

    void on_buttonTakaisinTilisiirto_clicked();

    void on_buttonLogoutTilisiirto_clicked();

    void on_buttonSendValues_clicked();

private:
    Ui::tilisiirto *ui;

signals:
    void sendCloseFromTilisiirto();
    void logoutTilisiirto();
    void sendTimerResetToEngineATMFromTilisiirto();
    void sendMoneyTodayFromTilisiirto(QString, QString, QString, QString, QString);
    void sendMoneyFutureFromTilisiirto(QString, QString, QString, QString, QString);

protected:
    void keyPressEvent(QKeyEvent *eventKey);
    void mousePressEvent(QMouseEvent *eventMouse);

public slots:
    void receiveCloseTilisiirto();
    void receiveMoneyActionResultFromEngineATM(QString);
    void receiveFutureActionResultFromEngineATM(QString);
    void receivenimiToTilisiirtoFromEngineATM(QString, QString);
};

#endif // TILISIIRTO_H
