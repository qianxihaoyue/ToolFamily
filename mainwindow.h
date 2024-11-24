#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include"screenshotwidget.h"

#include <QMainWindow>

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

private slots:
    void on_actionScreenShot_triggered();

private:
    Ui::MainWindow *ui;
    ScreenShotWidget *screenshotwidget_1;
};
#endif // MAINWINDOW_H
