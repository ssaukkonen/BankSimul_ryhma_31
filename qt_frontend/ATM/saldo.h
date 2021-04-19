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
};

#endif // SALDO_H
