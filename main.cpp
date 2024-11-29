#include "mainwindow.h"
#include <QApplication>
#include<QHotkey>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    auto startKey = new QHotkey(QKeySequence("Ctrl+Alt+A"), true,&w);
    QObject::connect(startKey, &QHotkey::activated, &w,[&w]{
        w.on_actionScreenShot_triggered();
    });

    w.show();
    return a.exec();
}
