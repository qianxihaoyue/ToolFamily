#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"screenshotwidget.h"
#include<QHotkey>
#include <QMainWindow>
#include <QSystemTrayIcon>
#include<QIcon>
#include<QShortcut>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

// protected:
//     void changeEvent(QEvent *event) override ;

public slots:
    void on_actionScreenShot_triggered();

public:
    QAction* actionScreenShot;

private:
    Ui::MainWindow *ui;
    ScreenShotWidget *screenshotwidget_1;
    QSystemTrayIcon *trayIcon;
};
#endif // MAINWINDOW_H
