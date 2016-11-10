#ifndef MYCUSTOMTABWIDGET_H
#define MYCUSTOMTABWIDGET_H

#include <QtWidgets>
#include "helper.h"
#include "imagingthread.h"

class MyCustomTabWidget : public QDialog
{
    Q_OBJECT
public:
    explicit MyCustomTabWidget(QWidget *parent = 0);
    void setImage(QString path);
    void blurMyImage(int numberofpasses);
    void convertGreyscale();
    QProgressDialog * m_progress;
    int m_progress_counter;
    QImage *greyed_image() const;
    void setGreyed_image(QImage *greyed_image);

signals:

public slots:
    void updateProgress();
    void onThreadFinish();
private:
    QImage * m_original_image;
    QImage * m_blurred_image;
    QImage * m_greyed_image;
    QHBoxLayout * m_main_layout;
    QVBoxLayout * m_original_layout;
    QVBoxLayout * m_blurred_layout;
    QLabel * m_original_label;
    QLabel * m_blurred_label;
    QLabel * m_original_image_label;
    QLabel * m_blurred_image_label;
    qint64 m_time_spent;

};

#endif // MYCUSTOMTABWIDGET_H
