#include "cutwidget.h"
#include "ui_cutwidget.h"

CutWidget::CutWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CutWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("裁剪界面");



}

CutWidget::~CutWidget()
{
    delete ui;
}
