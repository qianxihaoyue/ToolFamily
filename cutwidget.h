#ifndef CUTWIDGET_H
#define CUTWIDGET_H

#include <QWidget>
#include<QStyle>
namespace Ui {
class CutWidget;
}

class CutWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CutWidget(QWidget *parent = nullptr);
    ~CutWidget();

private:
    Ui::CutWidget *ui;
};

#endif // CUTWIDGET_H
