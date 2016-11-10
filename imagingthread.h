#ifndef IMAGINGTHREAD_H
#define IMAGINGTHREAD_H

#include <QThread>
#include <QObject>
#include <QtWidgets>
#include "helper.h"
#include "mycustomtabwidget.h"

class ImagingThread : public QThread
{
    Q_OBJECT
public:
    ImagingThread(MyCustomTabWidget* m, int num, QProgressDialog * p);
    virtual void run();
    int m_numberofpasses;
    QProgressDialog * m_progress;
    MyCustomTabWidget* m_tab;

signals:
    void renderedImage(QImage * p);

};

#endif // IMAGINGTHREAD_H
