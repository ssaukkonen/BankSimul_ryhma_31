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
    void on_buttonValikkoLogout_clicked();

    void on_buttonNosto_clicked();

signals:
    void logoutValikko();
    void sendOpenNostoToEngine();

private:
    Ui::Valikko *ui;
};

#endif // VALIKKO_H
