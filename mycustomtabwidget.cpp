#include "mycustomtabwidget.h"
//--------------------------------------------------------------------------------------------------
MyCustomTabWidget::MyCustomTabWidget(QWidget *parent) : QDialog(parent)
{
    m_original_image = new QImage();
    m_blurred_image = new QImage();
    m_greyed_image = new QImage();

    m_main_layout = new QHBoxLayout;
    m_original_layout = new QVBoxLayout;
    m_blurred_layout = new QVBoxLayout;

    m_original_label = new QLabel("Original");
    m_blurred_label = new QLabel("Blurred");

    m_original_image_label = new QLabel();
    m_original_image_label->setFrameStyle(1);

    m_original_image_label->setFixedHeight(250);
    m_original_image_label->setFixedWidth(250);

    m_blurred_image_label = new QLabel();
    m_blurred_image_label->setFrameStyle(1);

    m_blurred_image_label->setFixedHeight(250);
    m_blurred_image_label->setFixedWidth(250);


    m_main_layout->addLayout(m_original_layout);
    m_main_layout->addLayout(m_blurred_layout);
    this->setLayout(m_main_layout);

    m_original_layout->addWidget(m_original_label);
    m_original_layout->addWidget(m_original_image_label);


    m_blurred_layout->addWidget(m_blurred_label);
    m_blurred_layout->addWidget(m_blurred_image_label);

}
//--------------------------------------------------------------------------------------------------
void MyCustomTabWidget::setImage(QString path)
{
    if(m_original_image->load(path)){
        qDebug() << "Image was loaded successfully.";
        QPixmap pixmap_from_image = QPixmap::fromImage(*m_original_image);
        pixmap_from_image = pixmap_from_image.scaled(250,250);
        // QPixmap pixmap_of_original_image = QPixmap::fromImage(*m_original_image);
        m_original_image_label->setPixmap(pixmap_from_image);
        //m_original_image = m_original_image->scaled(200,200);
    }
    else
    {
        qDebug() << "Something went wrong when loading the file";
    }

}
//--------------------------------------------------------------------------------------------------
void MyCustomTabWidget::blurMyImage(int numberofpasses, QProgressDialog * progress)
{
    QImage temp = *m_greyed_image;
    for(int i=0;i<numberofpasses;i++)
    {
        progress->setValue(i);
        blurImage(m_greyed_image);
    }
    *m_blurred_image = *m_greyed_image;
    *m_greyed_image = temp;
    QPixmap pixmap_from_image = QPixmap::fromImage(*m_blurred_image);
    pixmap_from_image = pixmap_from_image.scaled(250,250);
    m_blurred_image_label->setPixmap(pixmap_from_image);
}
//--------------------------------------------------------------------------------------------------
void MyCustomTabWidget::convertGreyscale()
{
    QImage temp = *m_original_image;
    convertGrayscale(m_original_image);
    *m_greyed_image = *m_original_image;
    *m_original_image = temp;
    QPixmap pixmap_from_image = QPixmap::fromImage(*m_greyed_image);
    pixmap_from_image = pixmap_from_image.scaled(250,250);
    m_original_image_label->setPixmap(pixmap_from_image);

}
//--------------------------------------------------------------------------------------------------
QImage *MyCustomTabWidget::greyed_image() const
{
    return m_greyed_image;
}
//--------------------------------------------------------------------------------------------------
void MyCustomTabWidget::setGreyed_image(QImage *greyed_image)
{
    m_greyed_image = greyed_image;
}
