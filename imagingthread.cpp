#include "imagingthread.h"

ImagingThread::ImagingThread(MyCustomTabWidget* m, int num)
{
    m_tab = m;
    m_numberofpasses = num;
}

void ImagingThread::run()
{
    m_tab->blurMyImage(m_numberofpasses);
}

QImage *ImagingThread::rendered_image() const
{
    return m_rendered_image;
}

void ImagingThread::setRendered_image(QImage *rendered_image)
{
    m_rendered_image = rendered_image;
}
