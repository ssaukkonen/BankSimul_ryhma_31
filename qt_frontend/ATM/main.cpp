#include "mainwindow.h"
#include "timerevent.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    timerEvent * ptimerEvent = new timerEvent;
    a.installEventFilter(ptimerEvent);
    MainWindow w;
    w.show();
    return a.exec();
}
