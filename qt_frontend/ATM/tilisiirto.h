#ifndef TILISIIRTO_H
#define TILISIIRTO_H

#include <QDialog>

namespace Ui {
class tilisiirto;
}

class tilisiirto : public QDialog
{
    Q_OBJECT

public:
    explicit tilisiirto(QWidget *parent = nullptr);
    ~tilisiirto();

private:
    Ui::tilisiirto *ui;
};

#endif // TILISIIRTO_H
