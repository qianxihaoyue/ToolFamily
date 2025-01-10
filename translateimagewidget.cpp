#include "translateimagewidget.h"
#include "ui_translateimagewidget.h"

TranslateImageWidget::TranslateImageWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TranslateImageWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("图片转换界面");
    this->setWindowIcon(QIcon(":/sources/image_transform.png"));
    connect(ui->pushButton_0,&QPushButton::clicked,this,&TranslateImageWidget::on_pushbutton_openfile);
    view=ui->graphicsView;
    scene=new QGraphicsScene();
}

TranslateImageWidget::~TranslateImageWidget()
{
    delete ui;
}

void TranslateImageWidget::on_pushbutton_openfile()
{
    // QString filter = ;
    QString filename =QFileDialog::getOpenFileName(this,
                                                    "文件查找",
                                                    "./",
                                                    "Images (*.jpg);;All Files(*.*);;Images(*.png)"
                                                    );
    if (!filename.isEmpty()){
        this->m_have_image_flag=true;
        QImage image(filename); // 替换为你的图片路径
        if (image.isNull()) {
            qDebug()<<"错误";
        }
        else{
            view->setScene(scene);
            QPixmap pixmap = QPixmap::fromImage(image);
            scene->addPixmap(pixmap);

            view->show();
            qDebug()<<"xxxxx";
        }

    }
}
