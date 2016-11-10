#include "imagingthread.h"

ImagingThread::ImagingThread(QImage* img, int num)
{
    m_image = img;
    m_numberofpasses = num;
    m_rendered_image = new QImage();

}
//--------------------------------------------------------------------------------------------------
void ImagingThread::run()
{
    m_timer.start();
    QImage * temp = new QImage();
    * temp = *m_image;
    for(int i = 0; i < m_numberofpasses;++i)
    {
        blurImage(temp);
        emit incProgress();
    }
    *m_rendered_image = *temp;
    m_elapsed = m_timer.elapsed();
    //qDebug()<< m_elapsed;

}

qint64 ImagingThread::elapsed() const
{
    return m_elapsed;
}

QImage *ImagingThread::rendered_image() const
{
    return m_rendered_image;
}

void ImagingThread::setRendered_image(QImage *rendered_image)
{
    m_rendered_image = rendered_image;
}
//--------------------------------------------------------------------------------------------------
