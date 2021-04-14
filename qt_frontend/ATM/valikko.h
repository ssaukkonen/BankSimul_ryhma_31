#ifndef VALIKKO_H
#define VALIKKO_H

#include <QDialog>
#include <QDebug>

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

private slots:
    void on_SaldoButton_clicked();

private:
    Ui::Valikko *ui;

signals:
    void SaldoMenu();

};

#endif // VALIKKO_H
