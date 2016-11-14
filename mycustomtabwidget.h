/*
 * “Copyright (c) <current year> Medicim NV. All rights reserved.
 * Confidential and for internal use only.
 * The content of this document constitutes proprietary
 * information of the Nobel Biocare group of companies.
 * Any disclosure, copying, distribution or use of any parts of the content of
 * this document by unauthorized parties is strictly prohibited.”
 */
#pragma once

#include <QtWidgets>
#include "helper.h"
#include "imagingthread.h"

class MyCustomTabWidget : public QDialog
{
    Q_OBJECT
public:
    explicit MyCustomTabWidget(QWidget *parent = 0);
    void initImage(QString path);
    void initGUI();

    int getProgressCounter() const;
    void setProgressCounter(int getProgressCounter);

    QProgressDialog *getProgress() const;
    void setProgress(QProgressDialog *getProgress);
    QImage *getOriginalImage() const;
    void setoriginalImage(QImage *getOriginalImage);

public slots:
    void updateProgress();
    void onThreadFinish();
private:
    QProgressDialog * m_progress;
    int m_progress_counter;
    QImage * m_original_image;
    QImage * m_blurred_image;
    QHBoxLayout * m_main_layout;
    QVBoxLayout * m_original_layout;
    QVBoxLayout * m_blurred_layout;
    QLabel * m_original_label;
    QLabel * m_blurred_label;
    QLabel * m_original_image_label;
    QLabel * m_blurred_image_label;
    qint64 m_time_spent;

};
