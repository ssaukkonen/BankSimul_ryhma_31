#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include <QDialog>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

namespace Ui {
class tilitapahtumat;
}

class tilitapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit tilitapahtumat(QWidget *parent = nullptr);
    ~tilitapahtumat();

private:
    Ui::tilitapahtumat *ui;
    int pagenumber = 0;
    int tapahtuma = 0;

public slots:
    void receiveActionsFromEngineATM(QByteArray);
    void receiveFutureActionsToTilitapahtumat(QByteArray);
private slots:
    void on_NextButton_clicked();
    void on_PreviousButton_clicked();
    void on_buttonTakaisinTilitapahtumat_clicked();
    void receiveCloseTilitapahtumat();
    void on_buttonLogoutTilitapahtumat_clicked();
    void on_buttonTulevat_clicked();

signals:
    void requestActionsFromTilitapahtumat(int);
    void sendCloseFromTilitapahtumat();
    void logoutTilitapahtumat();
    void sendTimerResetFromTilitapahtumat();
    void requestFutureActionsFromTilitapahtumat(int);
};

#endif // TILITAPAHTUMAT_H
