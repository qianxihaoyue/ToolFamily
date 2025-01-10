#include "translateimagewidget.h"
#include "ui_translateimagewidget.h"

TranslateImageWidget::TranslateImageWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TranslateImageWidget)
{
    ui->setupUi(this);
    this->m_have_image_flag=false;
    this->setWindowTitle("图片转换界面");
    this->setWindowIcon(QIcon(":/sources/image_transform.png"));
    connect(ui->pushButton_0,&QPushButton::clicked,this,&TranslateImageWidget::on_pushbutton0_openfile);
    view=ui->graphicsView;
    scene=new QGraphicsScene();
    image=new QImage();
    image_path=nullptr;
    connect(ui->pushButton_1,&QPushButton::clicked,this,&TranslateImageWidget::on_pushbutton1_trans);
}

TranslateImageWidget::~TranslateImageWidget()
{
    delete ui;
}

void TranslateImageWidget::on_pushbutton0_openfile()
{
    // QString filter = ;
    QString temp_image_path=QFileDialog::getOpenFileName(this,
                                                    "文件查找",
                                                    "./",
                                                    "Images (*.jpg);;All Files(*.*);;Images(*.png)"
                                                    );
    image_path=&temp_image_path;
    qDebug()<<image_path;
    if (!temp_image_path.isEmpty()){
        this->m_have_image_flag=true;
        image->load(temp_image_path); // 替换为你的图片路径
        if (image->isNull()) {
            qDebug()<<"错误";
        }
        else{
            view->setScene(scene);
            QPixmap pixmap = QPixmap::fromImage(*image);
            scene->addPixmap(pixmap);

            view->show();
            qDebug()<<"xxxxx";
        }

    }
}

void TranslateImageWidget::on_pushbutton1_trans()
{
    if(image->isNull())
    {
        qDebug()<<"empty";
    }
    else{

        QString temp_save_path=QFileDialog::getSaveFileName(this,"保存图片","./",tr("Images (*.png)"));
        qDebug()<<"xxxxxxxxxxxxxxxxxxxxxx"<<temp_save_path;
        // QString name=(*image_path).split(".")[0];
        // QString save_path=name;
        image->save(temp_save_path,"PNG");
        qDebug()<<"成功";
    }
}
