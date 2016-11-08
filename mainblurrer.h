#ifndef MAINBLURRER_H
#define MAINBLURRER_H

#include <QDialog>
#include <QtWidgets>

class QLabel;
class QLineEdit;
class QTextEdit;

class MainBlurrer : public QDialog
{
    Q_OBJECT

public:
    explicit MainBlurrer(QWidget *parent = 0);
    ~MainBlurrer();
private:
    QString m_title;
};

#endif // MAINBLURRER_H
