/*
 * “Copyright (c) <current year> Medicim NV. All rights reserved.
 * Confidential and for internal use only.
 * The content of this document constitutes proprietary
 * information of the Nobel Biocare group of companies.
 * Any disclosure, copying, distribution or use of any parts of the content of
 * this document by unauthorized parties is strictly prohibited.”
 */
#include "imagingthread.h"

ImagingThread::ImagingThread(QImage* img, int num)
{
    m_image = img;
    m_numberofpasses = num;
    m_rendered_image = nullptr;

}
//--------------------------------------------------------------------------------------------------
void ImagingThread::run()
{
    m_timer.start();
    QImage * temp = new QImage(*m_image);
    for(int i = 0; i < m_numberofpasses;++i)
    {
        blurImage(temp);
        emit incProgress();
    }
    m_rendered_image = new QImage(*temp);
    m_elapsed = m_timer.elapsed();
}
//--------------------------------------------------------------------------------------------------
qint64 ImagingThread::elapsed() const
{
    return m_elapsed;
}
//--------------------------------------------------------------------------------------------------
QProgressDialog *ImagingThread::getProgress() const
{
    return m_progress;
}
//--------------------------------------------------------------------------------------------------
void ImagingThread::setProgress(QProgressDialog *progress)
{
    m_progress = progress;
}
//--------------------------------------------------------------------------------------------------
int ImagingThread::getNumberofpasses() const
{
    return m_numberofpasses;
}
//--------------------------------------------------------------------------------------------------
void ImagingThread::setNumberofpasses(int numberofpasses)
{
    m_numberofpasses = numberofpasses;
}
//--------------------------------------------------------------------------------------------------
QImage *ImagingThread::rendered_image() const
{
    return m_rendered_image;
}
//--------------------------------------------------------------------------------------------------
void ImagingThread::setRendered_image(QImage *rendered_image)
{
    m_rendered_image = rendered_image;
}
//--------------------------------------------------------------------------------------------------
