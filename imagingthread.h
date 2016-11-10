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
    ImagingThread(MyCustomTabWidget* m, int num);
    virtual void run();
    int m_numberofpasses;
    QImage * m_image;
    QImage * m_rendered_image;
    QImage *rendered_image() const;
    MyCustomTabWidget* m_tab;
    void setRendered_image(QImage *rendered_image);

signals:
    void renderedImage(QImage * p);

};

#endif // IMAGINGTHREAD_H
