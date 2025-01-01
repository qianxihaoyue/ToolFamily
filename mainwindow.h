#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"screenshotwidget.h"
#include"cutwidget.h"
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

protected:
    // void changeEvent(QEvent *event) override ;
    void closeEvent(QCloseEvent *event) override;

public slots:
    //toobar
    void on_actionScreenShot_triggered();
    void on_actionCut_triggered();

    //traymenu
    void on_action_close();
    void on_action_show();


private:
    Ui::MainWindow *ui;
    ScreenShotWidget *screenshotwidget_1;
    CutWidget  *cutwidget_1;
    //底部托盘
    QSystemTrayIcon *trayIcon;
    //toolbaraction
    QAction* actionScreenShot;
    QAction* actionCut;
};
#endif // MAINWINDOW_H
