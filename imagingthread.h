#ifndef IMAGINGTHREAD_H
#define IMAGINGTHREAD_H

#include <QThread>
#include <QObject>
#include <QtWidgets>
#include "helper.h"
#include "mycustomtabwidget.h"
#include <QElapsedTimer>

class ImagingThread : public QThread
{
    Q_OBJECT
public:
    ImagingThread(QImage *img, int num);
    virtual void run();
    int m_numberofpasses;
    QProgressDialog * m_progress;
    QImage * m_image;
    QImage * m_rendered_image;
    QElapsedTimer m_timer;
    qint64 m_elapsed;
    QImage *rendered_image() const;
    void setRendered_image(QImage *rendered_image);

    qint64 elapsed() const;

signals:
    void renderedImage(QImage * p);
    void incProgress();

};

#endif // IMAGINGTHREAD_H
