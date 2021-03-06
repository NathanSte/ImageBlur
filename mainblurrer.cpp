/*
 * “Copyright (c) <current year> Medicim NV. All rights reserved.
 * Confidential and for internal use only.
 * The content of this document constitutes proprietary
 * information of the Nobel Biocare group of companies.
 * Any disclosure, copying, distribution or use of any parts of the content of
 * this document by unauthorized parties is strictly prohibited.”
 */
#include "mainblurrer.h"

#include <QDebug>
#include <QDir>

namespace {
    const int INIT_DROPDOWN_BOX_COUNT = 11;
}

MainBlurrer::MainBlurrer(QWidget *parent) :
    QDialog(parent)
{
    initGUI();
}
//--------------------------------------------------------------------------------------------------
MainBlurrer::~MainBlurrer()
{
    //Free all non QT Variables
}
//--------------------------------------------------------------------------------------------------
void MainBlurrer::showFolderSelectDialog()
{
    QString dir;
    if(m_set_folder_line->text().isEmpty())
    {
        dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    }
    else{
       dir = m_set_folder_line->text();
    }
    m_set_folder_line->setText(dir);
    generateImagesFromDir(dir);
}
//--------------------------------------------------------------------------------------------------
void MainBlurrer::blurAllTabs()
{
    for(int i = 0; i < m_tabwidget->count();++i)
    {
        MyCustomTabWidget* singletab = dynamic_cast<MyCustomTabWidget*>(m_tabwidget->widget(i));
        QString box_value = this->m_drop_down_menu_passes->currentText();

        singletab->getProgress()->setMaximum(box_value.toInt());
        ImagingThread* my_thread = new ImagingThread(singletab->getOriginalImage(), box_value.toInt());
        connect(my_thread, &QThread::finished, singletab, &MyCustomTabWidget::onThreadFinish);
        connect(my_thread, &QThread::finished, this, &MainBlurrer::onThreadFinish);
        connect(my_thread, &QThread::finished, my_thread, &QThread::deleteLater);
        connect(my_thread, &ImagingThread::incProgress, singletab ,&MyCustomTabWidget::updateProgress);
        my_thread->start();
    }
}
//--------------------------------------------------------------------------------------------------
void MainBlurrer::onThreadFinish()
{
    ImagingThread * img_thread = dynamic_cast<ImagingThread*>(sender());
    if(m_time_spent < img_thread->getElapsed())
    {
        m_time_spent = img_thread->getElapsed();
        m_time_label->setText("Total Time: " + QString::number(m_time_spent) + " ms.");
    }

}
//--------------------------------------------------------------------------------------------------
void MainBlurrer::initGUI()
{
    m_blur_disable = true;
    m_step_dropdown_disable = true;
    m_time_spent = 0;

    QIcon *myicon = new QIcon(":/program_icon");

    QLabel* img_folder_label = new QLabel(tr("Image Folder"));
    QLabel* num_pass_label = new QLabel(tr("Number of Passes"));

    m_set_folder_line = new QLineEdit;

    QPushButton* set_folder_push_button = new QPushButton("Set Folder");
    this->m_start_blurring_push_button = new QPushButton("Start Blurring");

    QLabel* healder_label1 = new QLabel(tr("Input a folder of images and let the blurring begin."));
    QPixmap* qPM = new QPixmap(":/Image1");

    m_drop_down_menu_passes = new QComboBox();

    //Populates the dropdown menu
    for(int i = 1; i<::INIT_DROPDOWN_BOX_COUNT;i++)
    {
        m_drop_down_menu_passes->addItem(QString::fromStdString(std::to_string(i)));
    }
    m_drop_down_menu_passes->setCurrentIndex(5);//Sets default

    QLabel* imageLabel = new QLabel();
    imageLabel->setPixmap(qPM->scaled(32,32,Qt::KeepAspectRatio));

    QLabel* healder_label_main = new QLabel(tr("Multi Blur Images"));
    QFont font = healder_label_main->font();
    font.setBold(true);
    healder_label_main->setFont(font);
    healder_label_main->setMinimumWidth(500);

    QVBoxLayout* main_layout = new QVBoxLayout; //This is the main layout.

    //Populate the header.
    QGridLayout* header_layout = new QGridLayout;//contains the header.
    header_layout->addWidget(imageLabel,0,0,2,1);
    header_layout->addWidget(healder_label_main,0,1);
    header_layout->addWidget(healder_label1,1,1);

    QVBoxLayout* bottom_layout = new QVBoxLayout;//Contains the rest of the application

    QHBoxLayout* bottom_Hlayout1 = new QHBoxLayout;
    bottom_Hlayout1->addWidget(img_folder_label,0,Qt::AlignLeft);
    bottom_Hlayout1->addWidget(m_set_folder_line,0);
    bottom_Hlayout1->addWidget(set_folder_push_button);

    QHBoxLayout* bottom_Hlayout2 = new QHBoxLayout;
    bottom_Hlayout2->addWidget(num_pass_label);
    bottom_Hlayout2->addWidget(m_drop_down_menu_passes);
    bottom_Hlayout2->addWidget(m_start_blurring_push_button);
    bottom_Hlayout2->addStretch();

    m_tabwidget = new QTabWidget;
    initTabWidget();

    QHBoxLayout* bottom_Hlayout3 = new QHBoxLayout;
    bottom_Hlayout3->addWidget(m_tabwidget);

    QHBoxLayout* bottom_Hlayout4 = new QHBoxLayout;

    QPushButton* push_button_exit = new QPushButton("Exit");

    m_time_label = new QLabel(tr("Total Time: -"));
    bottom_Hlayout4->addWidget(m_time_label,0,Qt::AlignLeft);
    bottom_Hlayout4->addWidget(push_button_exit,0,Qt::AlignRight);

    QFrame * mFrame = new QFrame(this);//Must pass this to maintain parent
    mFrame->setFrameStyle(1);
    mFrame->setLayout(bottom_layout);//This frame has the bottom layout

    bottom_layout->addLayout(bottom_Hlayout1);
    bottom_layout->addLayout(bottom_Hlayout2);
    bottom_layout->addLayout(bottom_Hlayout3);
    bottom_layout->addLayout(bottom_Hlayout4);

    main_layout->addLayout(header_layout);
    main_layout->addWidget(mFrame);
    // Signal and Slot connections
    QObject::connect(push_button_exit,&QPushButton::clicked,this,&QPushButton::close);
    QObject::connect(set_folder_push_button,&QPushButton::clicked,this,&MainBlurrer::showFolderSelectDialog);
    QObject::connect(m_start_blurring_push_button,&QPushButton::clicked,this,&MainBlurrer::blurAllTabs);
    //Main GUI
    setLayout(main_layout);
    setWindowIcon(*myicon); //Sets the icon, increases Reference count to icon
    setWindowTitle(tr("ImageBlurrer v1.0"));
}


//--------------------------------------------------------------------------------------------------
void MainBlurrer::generateImagesFromDir(QString dir)
{
    QDirIterator it(dir, QDirIterator::Subdirectories);
    m_tabwidget->clear();
    int validfiles = 0;
    while (it.hasNext()){
        it.next();
        QFileInfo finfo = it.fileInfo();
        QString fname = it.fileName();
        QString fpath = it.filePath();
        if(fname != "." && fname != ".."){
            QString ext = finfo.suffix();
            QString raw_name = finfo.baseName();
            if(ext == "jpg" || ext == "png" ||ext == "tif" ||ext == "bmp"){//find a cleaner way of doing this
                validfiles++;
                m_tabwidget->addTab(imagehelpspace::ImageTabGenerator::generateSingleTabFromPath(fpath), raw_name);
            }
        }
    }
    if (validfiles == 0) {
        initTabWidget();
    }
    else{
        m_drop_down_menu_passes->setDisabled(false);
        m_start_blurring_push_button->setDisabled(false);
    }
}
//--------------------------------------------------------------------------------------------------
void MainBlurrer::initTabWidget()
{
    MyCustomTabWidget * main_dialog = new MyCustomTabWidget();
    delete main_dialog->getProgress();//Our default doesnt need one, do this to prevent it from showing.
    m_tabwidget->addTab(main_dialog,"No Results");

    m_start_blurring_push_button->setDisabled(true);
    m_drop_down_menu_passes->setDisabled(true);
}
