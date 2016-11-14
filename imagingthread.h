/*
 * “Copyright (c) <current year> Medicim NV. All rights reserved.
 * Confidential and for internal use only.
 * The content of this document constitutes proprietary
 * information of the Nobel Biocare group of companies.
 * Any disclosure, copying, distribution or use of any parts of the content of
 * this document by unauthorized parties is strictly prohibited.”
 */
#pragma once

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
    QImage *getRenderedImage() const;
    void setRenderedImage(QImage *getRenderedImage);
    qint64 getElapsed() const;

    QProgressDialog *getProgress() const;
    void setProgress(QProgressDialog *getProgress);

    int getNumberofpasses() const;
    void setNumberofpasses(int numberofpasses);

signals:
    void incProgress();

private:
    qint64 m_elapsed;
    QElapsedTimer m_timer;
    QImage * m_rendered_image;
    QImage * m_image;
    QProgressDialog * m_progress;
    int m_numberofpasses;


};

