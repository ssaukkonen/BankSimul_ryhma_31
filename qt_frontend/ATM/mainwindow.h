#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "engineatm.h"
#include "pin.h"
#include <QObject>
#include "nosto.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    engineatm *pengineatm;
//    pin * ppin;
    nosto * pnosto;

public slots:
    void SignalFromEngineRfidToExe();

private slots:
    void on_pushButton_clicked();

};
#endif // MAINWINDOW_H
