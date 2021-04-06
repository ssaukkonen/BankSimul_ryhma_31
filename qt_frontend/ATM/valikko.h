#ifndef VALIKKO_H
#define VALIKKO_H

#include <QDialog>

namespace Ui {
class Valikko;
}

class Valikko : public QDialog
{
    Q_OBJECT

public:
    explicit Valikko(QWidget *parent = nullptr);
    ~Valikko();

private:
    Ui::Valikko *ui;
};

#endif // VALIKKO_H
