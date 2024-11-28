#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"screenshotwidget.h"

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

protected:
    void changeEvent(QEvent *event) override ;

private slots:
    void on_actionScreenShot_triggered();



private:
    Ui::MainWindow *ui;
    ScreenShotWidget *screenshotwidget_1;
    QSystemTrayIcon *trayIcon;
};
#endif // MAINWINDOW_H
