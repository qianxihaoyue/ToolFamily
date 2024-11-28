#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,screenshotwidget_1(nullptr)
{
    ui->setupUi(this);
    this->setWindowTitle("ToolFamily");


    QAction* actionScreenShot=ui->toolBar->findChild<QAction*>("actionScreenShot");
    connect(actionScreenShot,&QAction::triggered,this,&MainWindow::on_actionScreenShot_triggered);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/sources/tools.png"));
    trayIcon->setToolTip("ToolFamily");


    connect(trayIcon, &QSystemTrayIcon::activated, [&](QSystemTrayIcon::ActivationReason reason) {
        if (reason == QSystemTrayIcon::Trigger) {

            this->show();
            //窗口设置为活动，并至于顶层
            this->setWindowState(Qt::WindowActive);
            this->activateWindow();
        }
    });
    trayIcon->show();

    // QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+Alt+A"), this);
    // connect(shortcut, &QShortcut::activated,this,&MainWindow::on_actionScreenShot_triggered);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionScreenShot_triggered()
{
    if(screenshotwidget_1!=nullptr){
        screenshotwidget_1->deleteLater();
        screenshotwidget_1=nullptr;
    }
    // this->setWindowOpacity(0);
    screenshotwidget_1=new ScreenShotWidget();
    screenshotwidget_1->showFullScreen();
    // this->setWindowOpacity(1);
}



void MainWindow::changeEvent(QEvent *event)  {
    if (event->type() == QEvent::WindowStateChange) {
        if (this->windowState() & Qt::WindowMinimized) {
            this->hide();
        }
    }
}

