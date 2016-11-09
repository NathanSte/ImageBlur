#ifndef IMAGINGTHREAD_H
#define IMAGINGTHREAD_H

#include <QThread>
#include <QObject>
#include <QtWidgets>

class ImagingThread : public QThread
{
    Q_OBJECT
public:
    ImagingThread();
};

#endif // IMAGINGTHREAD_H
