#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,screenshotwidget_1(nullptr)
    ,translate_image_widget_1(nullptr)
{
    ui->setupUi(this);
    this->setWindowTitle("ToolFamily");


    //toolbar
    actionScreenShot=ui->toolBar->findChild<QAction*>("actionScreenShot");
    connect(actionScreenShot,&QAction::triggered,this,&MainWindow::on_actionScreenShot_triggered);
    actionCut=ui->toolBar->findChild<QAction*>("actionCut");
    connect(actionCut,&QAction::triggered,this,&MainWindow::on_actionCut_triggered);
    actionTranslate=ui->toolBar->findChild<QAction*>("actionTranslate");
     connect(actionTranslate,&QAction::triggered,this,&MainWindow::on_actionTranslate_triggered);


    //底部托盘
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/sources/tools.png"));
    trayIcon->setToolTip("ToolFamily");
    QMenu* trayMenu = new QMenu(this);;
    trayMenu->addAction("Exit", this, &MainWindow::on_action_close);
    trayMenu->addAction("Show", this, &MainWindow::on_action_show);
    trayIcon->setContextMenu(trayMenu);




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

void MainWindow::closeEvent(QCloseEvent *event)
{
    this->hide();
    event->ignore();
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


void MainWindow::on_actionCut_triggered()
{
    qDebug()<<"on_actionCut_triggered";
    cutwidget_1=new CutWidget();
    cutwidget_1->show();
}

void MainWindow::on_actionTranslate_triggered()
{
    qDebug()<<"on_actionTranslate_triggered";
    translate_image_widget_1=new TranslateImageWidget();
    translate_image_widget_1->show();
}


void MainWindow::on_action_close()
{
    this->close();
    QApplication::exit(0);
}

void MainWindow::on_action_show()
{
    this->show();
    //窗口设置为活动，并至于顶层
    this->setWindowState(Qt::WindowActive);
    this->activateWindow();
}



// void MainWindow::changeEvent(QEvent *event)  {
//     if (event->type() == QEvent::WindowStateChange) {
//         if (this->windowState() & Qt::WindowMinimized) {
//             this->hide();
//         }
//     }
// }

