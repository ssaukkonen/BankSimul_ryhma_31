#ifndef VALIKKO_H
#define VALIKKO_H

#include <QDialog>
#include <QDebug>
#include <QTimer>

namespace Ui {
class Valikko;
}

class Valikko : public QDialog
{
    Q_OBJECT

public:
    explicit Valikko(QWidget *parent = nullptr);
    ~Valikko();

public slots:
    void receiveFnameLnameFromEngineATM(QString, QString);
    void receiveCloseValikko();

private slots:


signals:
    void logoutValikko();

private slots:
    void on_SaldoButton_clicked();
    void on_TilitapahtumatButton_clicked();
    void on_buttonValikkoLogout_clicked();

private:
    Ui::Valikko *ui;


signals:
    void SaldoMenu();
    void TilitapahtumatMenu();



};

#endif // VALIKKO_H
