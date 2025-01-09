#ifndef TRANSLATEIMAGEWIDGET_H
#define TRANSLATEIMAGEWIDGET_H

#include <QWidget>

namespace Ui {
class TranslateImageWidget;
}

class TranslateImageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TranslateImageWidget(QWidget *parent = nullptr);
    ~TranslateImageWidget();

private:
    Ui::TranslateImageWidget *ui;
};

#endif // TRANSLATEIMAGEWIDGET_H
