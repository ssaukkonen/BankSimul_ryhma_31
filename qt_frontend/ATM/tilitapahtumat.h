#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include <QDialog>

namespace Ui {
class tilitapahtumat;
}

class tilitapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit tilitapahtumat(QWidget *parent = nullptr);
    ~tilitapahtumat();

private:
    Ui::tilitapahtumat *ui;
};

#endif // TILITAPAHTUMAT_H
