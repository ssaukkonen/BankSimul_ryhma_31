#ifndef NOSTO_H
#define NOSTO_H

#include <QDialog>
#include "engineatm.h"

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

private:
    Ui::nosto *ui;
    QString amount;
    engineatm * pengineAtmNosto;

signals:
    void SignalToEngineFromNosto(QString);
};

#endif // NOSTO_H
