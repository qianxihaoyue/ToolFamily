#include "translateimage.h"
#include "ui_translateimage.h"

TranslateImage::TranslateImage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TranslateImage)
{
    ui->setupUi(this);
}

TranslateImage::~TranslateImage()
{
    delete ui;
}
