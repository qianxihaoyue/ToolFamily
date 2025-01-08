#ifndef SCREENSHOTWIDGET_H
#define SCREENSHOTWIDGET_H

#include <QApplication>
#include <QCoreApplication>
#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QScreen>
#include <QPen>
#include <QPushButton>
#include <QDateTime>
#include <QTime>
#include <QPixmap>
#include <QThread>
#include <QDebug>
#include <QLabel>
#include <QScreen>
#include<QToolBar>
#include<QFileDialog>
#include<QClipboard>



class ScreenShotWidget : public QWidget
{
    Q_OBJECT
public:
    ScreenShotWidget(QWidget *parent = nullptr);


protected:
    //鼠标按下事件
    void mousePressEvent(QMouseEvent *event) override;
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event) override;
    //鼠标松开事件
    void mouseReleaseEvent(QMouseEvent *event) override;
    //绘制边框事件
    void paintEvent(QPaintEvent *event) override;




private slots:
    void on_buttonSave_Clicked();
    void on_buttonCancel_Clicked();
    void on_buttonTempStore_Clicked();
private:
    QPoint getPointInWhichSqure(QPoint point);

private:
    QPushButton *buttonSave;
    QPushButton *buttonCancel;
    QLabel *lblHeightWidth;
    QLabel *lblMagnifyGlass;

    QPainter m_painter;

    QPoint m_startPos;   //起始点
    QPoint m_endPos;     //结束点
    QPoint m_oldPos;
    QPoint m_distancePos;     //用于拖拽截图区域
    bool m_screenshot_active;

    QPoint m_topLeft;
    QPoint m_topRight;
    QPoint m_bottomLeft;
    QPoint m_bottomRight;
    QPoint m_topCenter;
    QPoint m_bottomCenter;
    QPoint m_leftCenter;
    QPoint m_rightCenter;
    int m_cursorMode;


    //工具栏相关
    QToolBar *toolbar;
    QAction* actionCancel;
    QAction* actionSave;
    QAction* actionTempStore; //暂存
};

#endif // SCREENSHOTWIDGET_H
