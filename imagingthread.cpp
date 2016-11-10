#include "imagingthread.h"

ImagingThread::ImagingThread(MyCustomTabWidget* m, int num, QProgressDialog * p)
{
    m_progress = p;
    m_tab = m;
    m_numberofpasses = num;

}
//--------------------------------------------------------------------------------------------------
void ImagingThread::run()
{
    m_tab->blurMyImage(m_numberofpasses,m_progress);
}
//--------------------------------------------------------------------------------------------------
