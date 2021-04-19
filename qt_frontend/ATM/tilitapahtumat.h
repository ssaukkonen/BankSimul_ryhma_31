#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include <QDialog>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

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
    int pagenumber = 0;

public slots:
    void receiveActionsFromEngineATM(QByteArray);
private slots:
    void on_NextButton_clicked();
    void on_PreviousButton_clicked();
signals:
    void NextTilitap(int);
    void PreviousTilitap(int);
};

#endif // TILITAPAHTUMAT_H
