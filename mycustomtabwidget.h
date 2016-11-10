#ifndef MYCUSTOMTABWIDGET_H
#define MYCUSTOMTABWIDGET_H

#include <QtWidgets>

class MyCustomTabWidget : public QDialog
{
    Q_OBJECT
public:
    explicit MyCustomTabWidget(QWidget *parent = 0);
    void setImage(QString path);
    void blurImage();

signals:

public slots:

private:
    QImage * m_original_image;
    QImage * m_blurred_image;
    QHBoxLayout * m_main_layout;
    QVBoxLayout * m_original_layout;
    QVBoxLayout * m_blurred_layout;
    QLabel * m_original_label;
    QLabel * m_blurred_label;
    QLabel * m_original_image_label;
    QLabel * m_blurred_image_label;

};

#endif // MYCUSTOMTABWIDGET_H
