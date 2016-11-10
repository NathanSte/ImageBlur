#ifndef MYCUSTOMTABWIDGET_H
#define MYCUSTOMTABWIDGET_H

#include <QtWidgets>
#include "helper.h"

class MyCustomTabWidget : public QDialog
{
    Q_OBJECT
public:
    explicit MyCustomTabWidget(QWidget *parent = 0);
    void setImage(QString path);
    void blurMyImage(int numberofpasses, QProgressDialog *progress);
    void convertGreyscale();

    QImage *greyed_image() const;
    void setGreyed_image(QImage *greyed_image);

signals:

public slots:

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

};

#endif // MYCUSTOMTABWIDGET_H
