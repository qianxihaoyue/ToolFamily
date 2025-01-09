#include "translateimagewidget.h"
#include "ui_translateimagewidget.h"

TranslateImageWidget::TranslateImageWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TranslateImageWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("图片转换界面");
}

TranslateImageWidget::~TranslateImageWidget()
{
    delete ui;
}
