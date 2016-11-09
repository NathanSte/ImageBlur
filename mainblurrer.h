#ifndef MAINBLURRER_H
#define MAINBLURRER_H
/*
 * “Copyright (c) <current year> Medicim NV. All rights reserved.
 * Confidential and for internal use only.
 * The content of this document constitutes proprietary
 * information of the Nobel Biocare group of companies.
 * Any disclosure, copying, distribution or use of any parts of the content of
 * this document by unauthorized parties is strictly prohibited.”
 */
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
private slots:
    void showFolderSelectDialog();
private:
    QDialog* generateSingleTabFromPath(QString path);
    void generateImagesFromDir(QString dir);
    void initTabWidget();
    std::vector<QWidget*> m_tabs;
    QTabWidget * m_tabwidget;
    QString m_title;
    bool m_blur_disable;
    bool m_step_dropdown_disable;
    QLineEdit * m_set_folder_line;
    QPushButton* m_start_blurring_push_button;
    QComboBox* m_drop_down_menu_passes;
};

#endif // MAINBLURRER_H
