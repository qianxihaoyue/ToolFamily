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
    screenshotwidget_1=new ScreenShotWidget();
    screenshotwidget_1->showFullScreen();
}

