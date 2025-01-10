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
    void on_pushbutton0_openfile();
    void on_pushbutton1_trans();
    // void on_pushbutton2_trans();
    // void on_pushbutton3_trans();
    // void on_pushbutton4_trans();

private:
    Ui::TranslateImageWidget *ui;

    bool m_have_image_flag;
    QGraphicsView *view;
    QGraphicsScene *scene;
    QImage *image;
    QString *image_path;
};

#endif // TRANSLATEIMAGEWIDGET_H
