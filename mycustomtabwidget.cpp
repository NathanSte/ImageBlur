/*
 * “Copyright (c) <current year> Medicim NV. All rights reserved.
 * Confidential and for internal use only.
 * The content of this document constitutes proprietary
 * information of the Nobel Biocare group of companies.
 * Any disclosure, copying, distribution or use of any parts of the content of
 * this document by unauthorized parties is strictly prohibited.”
 */
#include "mycustomtabwidget.h"
//--------------------------------------------------------------------------------------------------
MyCustomTabWidget::MyCustomTabWidget(QWidget *parent) : QDialog(parent)
{
    initGUI();

}
//--------------------------------------------------------------------------------------------------
void MyCustomTabWidget::initImage(QString path)
{
    if(m_original_image->load(path)){
        qDebug() << "Image was loaded successfully.";
        QPixmap pixmap_from_image = QPixmap::fromImage(*m_original_image);
        pixmap_from_image = pixmap_from_image.scaled(250,250);
        m_original_image_label->setPixmap(pixmap_from_image);
    }
    else
    {
        qDebug() << "Something went wrong when loading the file";
    }

}
//--------------------------------------------------------------------------------------------------

void MyCustomTabWidget::initGUI()
{
    m_original_image = new QImage();
    m_blurred_image = nullptr;

    m_progress = new QProgressDialog("Blurring Images", "Abort Blur",0,10,this);
    m_progress_counter = 0;
    m_progress->cancel();

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

void MyCustomTabWidget::updateProgress()
{
    m_progress->setHidden(false);
    this->m_progress_counter++;
    this->m_progress->setValue(m_progress_counter);
}
//--------------------------------------------------------------------------------------------------
void MyCustomTabWidget::onThreadFinish()
{
    ImagingThread * img_thread = dynamic_cast<ImagingThread*>(sender());
    m_blurred_image = new QImage(* img_thread->getRenderedImage());
    QPixmap pixmap_from_image = QPixmap::fromImage(*m_blurred_image);
    pixmap_from_image = pixmap_from_image.scaled(250,250);
    m_blurred_image_label->setPixmap(pixmap_from_image);
    m_time_spent = img_thread->getElapsed();
}
//--------------------------------------------------------------------------------------------------
QImage *MyCustomTabWidget::getOriginalImage() const
{
    return m_original_image;
}
//--------------------------------------------------------------------------------------------------
void MyCustomTabWidget::setoriginalImage(QImage *original_image)
{
    m_original_image = original_image;
}
//--------------------------------------------------------------------------------------------------
QProgressDialog *MyCustomTabWidget::getProgress() const
{
    return m_progress;
}

void MyCustomTabWidget::setProgress(QProgressDialog *progress)
{
    m_progress = progress;
}
//--------------------------------------------------------------------------------------------------
int MyCustomTabWidget::getProgressCounter() const
{
    return m_progress_counter;
}
//--------------------------------------------------------------------------------------------------
void MyCustomTabWidget::setProgressCounter(int progress_counter)
{
    m_progress_counter = progress_counter;
}
