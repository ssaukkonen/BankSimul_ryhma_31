#ifndef SALDO_H
#define SALDO_H

#include <QDialog>
#include <QJsonDocument>
#include <QJsonArray>
#include <QtNetwork>
#include <QNetworkAccessManager>

namespace Ui {
class saldo;
}

class saldo : public QDialog
{
    Q_OBJECT

public:
    explicit saldo(QWidget *parent = nullptr);
    ~saldo();

private:
    Ui::saldo *ui;

public slots:
    void receiveBalanceFromEngineATM(QString);
    void receiveActions5FromEngineATM(QByteArray);
    void receiveCloseSaldo();
private slots:
    void on_buttonTakaisinSaldo_clicked();

    void on_buttonLogoutSaldo_clicked();

signals:
    void sendCloseFromSaldo();
    void logoutSaldo();
};

#endif // SALDO_H
