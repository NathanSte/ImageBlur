/*
 * “Copyright (c) <current year> Medicim NV. All rights reserved.
 * Confidential and for internal use only.
 * The content of this document constitutes proprietary
 * information of the Nobel Biocare group of companies.
 * Any disclosure, copying, distribution or use of any parts of the content of
 * this document by unauthorized parties is strictly prohibited.”
 */
#pragma once
#include <QDialog>
#include <QtWidgets>
#include <QObject>
#include <QDebug>
#include <QDir>
#include "imagetabgenerator.h"
#include "imagingthread.h"

class MainBlurrer : public QDialog
{
    Q_OBJECT
public:
    explicit MainBlurrer(QWidget *parent = 0);
    ~MainBlurrer();
private slots:
    void showFolderSelectDialog();
    void blurAllTabs();
    void onThreadFinish();
private:
    void initGUI();
    void generateImagesFromDir(const QString dir);
    void initTabWidget();
    QTabWidget * m_tabwidget;
    QString m_title;
    bool m_blur_disable;
    bool m_step_dropdown_disable;
    QLineEdit * m_set_folder_line;
    QPushButton* m_start_blurring_push_button;
    QComboBox* m_drop_down_menu_passes;
    qint64 m_time_spent;
    QLabel* m_time_label;
};


