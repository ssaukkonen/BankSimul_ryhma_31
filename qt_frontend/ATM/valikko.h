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

signals:
    void logoutValikko();
    void SaldoMenu();
    void TilitapahtumatMenu();
    void NostaRahaaMenu();


private slots:
    void on_SaldoButton_clicked();
    void on_TilitapahtumatButton_clicked();
    void on_buttonValikkoLogout_clicked();

    void on_buttonNostaRahaa_clicked();

private:
    Ui::Valikko *ui;
};

#endif // VALIKKO_H
