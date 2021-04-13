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

private:
    Ui::Valikko *ui;

};

#endif // VALIKKO_H
