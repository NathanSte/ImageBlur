#include "mycustomtabwidget.h"

MyCustomTabWidget::MyCustomTabWidget(QWidget *parent) : QDialog(parent)
{
    m_original_image = new QImage();
    m_blurred_image = new QImage();

    m_main_layout = new QHBoxLayout;
    m_original_layout = new QVBoxLayout;
    m_blurred_layout = new QVBoxLayout;

    m_original_label = new QLabel("Original");
    m_blurred_label = new QLabel("Blurred");

    m_original_image_label = new QLabel();
    m_original_image_label->setFrameStyle(1);
    m_original_image_label->setMaximumHeight(200);
    m_original_image_label->setMaximumWidth(200);
    m_original_image_label->setFixedHeight(200);
    m_original_image_label->setFixedWidth(200);

    m_blurred_image_label = new QLabel();
    m_blurred_image_label->setFrameStyle(1);
    m_blurred_image_label->setMaximumHeight(200);
    m_blurred_image_label->setMaximumWidth(200);
    m_blurred_image_label->setFixedHeight(200);
    m_blurred_image_label->setFixedWidth(200);


    m_main_layout->addLayout(m_original_layout);
    m_main_layout->addLayout(m_blurred_layout);
    this->setLayout(m_main_layout);

    m_original_layout->addWidget(m_original_label);
    m_original_layout->addWidget(m_original_image_label);


    m_blurred_layout->addWidget(m_blurred_label);
    m_blurred_layout->addWidget(m_blurred_image_label);

}

void MyCustomTabWidget::setImage(QString path)
{
    if(m_original_image->load(path)){
        qDebug() << "Image was loaded successfully.";
        QPixmap pixmap_from_image = QPixmap::fromImage(*m_original_image);
        // QPixmap pixmap_of_original_image = QPixmap::fromImage(*m_original_image);
        m_original_image_label->setPixmap(pixmap_from_image);
        //m_original_image = m_original_image->scaled(200,200);
    }
    else
    {
        qDebug() << "Something went wrong when loading the file";
    }

}

void MyCustomTabWidget::blurImage()
{

}
