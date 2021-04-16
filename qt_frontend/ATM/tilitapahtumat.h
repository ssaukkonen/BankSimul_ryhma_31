#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include <QDialog>
#include <QDebug>

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

public slots:
    void receiveActionsFromEngineATM(QString);
private slots:
    void on_NextButton_clicked();
    void on_PreviousButton_clicked();
signals:
    void NextTilitap();
    void PreviousTilitap();
};

#endif // TILITAPAHTUMAT_H
