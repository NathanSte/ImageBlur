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
    void initTabWidget();
    std::vector<QWidget*> m_tabs;
    QTabWidget * m_tabwidget;
    QString m_title;
};

#endif // MAINBLURRER_H
