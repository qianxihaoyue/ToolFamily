#ifndef TRANSLATEIMAGEWIDGET_H
#define TRANSLATEIMAGEWIDGET_H

#include <QWidget>
#include<QFileDialog>
#include<QImage>
#include<QFileDialog>
#include<QGraphicsView>

namespace Ui {
class TranslateImageWidget;
}

class TranslateImageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TranslateImageWidget(QWidget *parent = nullptr);
    ~TranslateImageWidget();
public slots:
     void on_pushbutton_openfile();

private:
    Ui::TranslateImageWidget *ui;

    bool m_have_image_flag;
    QGraphicsView *view;
    QGraphicsScene *scene;
};

#endif // TRANSLATEIMAGEWIDGET_H
