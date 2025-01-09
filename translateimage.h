#ifndef TRANSLATEIMAGE_H
#define TRANSLATEIMAGE_H

#include <QWidget>

namespace Ui {
class TranslateImage;
}

class TranslateImage : public QWidget
{
    Q_OBJECT

public:
    explicit TranslateImage(QWidget *parent = nullptr);
    ~TranslateImage();

private:
    Ui::TranslateImage *ui;
};

#endif // TRANSLATEIMAGE_H
