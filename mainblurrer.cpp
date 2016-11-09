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


MainBlurrer::MainBlurrer(QWidget *parent) :
    QDialog(parent)
{
    m_blur_disable = true;
    m_step_dropdown_disable = true;

    QIcon *myicon = new QIcon(":/program_icon");

    QLabel* img_folder_label = new QLabel(tr("Image Folder"));
    QLabel* num_pass_label = new QLabel(tr("Number of Passes"));

    m_set_folder_line = new QLineEdit;

    QPushButton* set_folder_push_button = new QPushButton("Set Folder");
    this->m_start_blurring_push_button = new QPushButton("Start Blurring");

    QLabel* healder_label1 = new QLabel(tr("Input a folder of images and let the blurring begin."));
    QPixmap* qPM = new QPixmap(":/Image1");

    if(m_blur_disable)
    {
        this->m_start_blurring_push_button->setDisabled(true);
    }

    //Populate the combobox
    this->m_drop_down_menu_passes = new QComboBox();
    const int INIT_DROPDOWN_BOX_COUNT = 11;//Where should this be declared?
    for(int i = 1; i<INIT_DROPDOWN_BOX_COUNT;i++)
    {
        this->m_drop_down_menu_passes->addItem(QString::fromStdString(std::to_string(i)));
    }
    this->m_drop_down_menu_passes->setCurrentIndex(5);//Sets default
    if(m_step_dropdown_disable)
    {
        this->m_drop_down_menu_passes->setDisabled(true);
    }

    QLabel* imageLabel = new QLabel();
    imageLabel->setPixmap(qPM->scaled(32,32,Qt::KeepAspectRatio));
    this->setWindowIcon(*myicon); //Sets the icon, increases Reference count to icon
    this->setWindowTitle(tr("ImageBlurrer v1.0"));

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
    bottom_Hlayout1->addWidget(this->m_set_folder_line,0);
    bottom_Hlayout1->addWidget(set_folder_push_button);

    QHBoxLayout* bottom_Hlayout2 = new QHBoxLayout;
    bottom_Hlayout2->addWidget(num_pass_label);
    bottom_Hlayout2->addWidget(this->m_drop_down_menu_passes);
    bottom_Hlayout2->addWidget(this->m_start_blurring_push_button);
    bottom_Hlayout2->addStretch();

    m_tabwidget = new QTabWidget;
    this->initTabWidget();

    QHBoxLayout* bottom_Hlayout3 = new QHBoxLayout;
    bottom_Hlayout3->addWidget(m_tabwidget);

    QHBoxLayout* bottom_Hlayout4 = new QHBoxLayout;

    QPushButton* push_button_exit = new QPushButton("Exit");

    QObject::connect(push_button_exit,&QPushButton::clicked,this,&QPushButton::close);//Passing THIS as the receiver?
    QObject::connect(set_folder_push_button,&QPushButton::clicked,this,&MainBlurrer::showFolderSelectDialog);

    QLabel* time_label = new QLabel(tr("Total Time: -"));
    bottom_Hlayout4->addWidget(time_label,0,Qt::AlignLeft);
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

    this->setLayout(main_layout);

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
    if(m_set_folder_line->text().size() == 0)
    {
        dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);
    //Dir now contains the path...
    }
    else{
       dir = m_set_folder_line->text();
    }
    this->m_set_folder_line->setText(dir);
    this->m_drop_down_menu_passes->setDisabled(false);
    this->m_start_blurring_push_button->setDisabled(false);
    this->generateImagesFromDir(dir);
}
//--------------------------------------------------------------------------------------------------
void MainBlurrer::generateImagesFromDir(QString dir)
{
    QDirIterator it(dir, QDirIterator::Subdirectories);

    int validfiles = 0;

    while (it.hasNext()){
        it.next();
        QString fpath = it.fileName();
        if(fpath != "." && fpath != ".."){
            QString ext = fpath.section(".",1,1);
            qDebug() << ext;
            if(ext == "jpg" || ext == "png" ||ext == "tif" ||ext == "bmp"){//find a cleaner way of doing this
                validfiles++;
                //Generate a pane for this image
            }
        }
    }
    qDebug() << validfiles;

    if (validfiles == 0) return;//Find a cleaner way to exit.

    QDirIterator it2(dir, QDirIterator::Subdirectories);//Need a new iterator because no eay to go back to the start
    while (it2.hasNext())
    {
        //it starts at null, needs first next
        it2.next();
        QString filepath = it2.fileName();
        if(filepath != "." && filepath != ".."){
            //Generate the panes, do all the things.
        }
    }

}
//--------------------------------------------------------------------------------------------------
void MainBlurrer::initTabWidget()
{
    /* Pre: Tabwidget is empty
     * TODO:
     * 1) Create the Default tab Widget
     * 2) Prepare the vector for the to be read files.
     * 3) Choose a Layout
     * Post: Tabwidget has the default tab, which is empty.
     */
    //1 Tab consists of 1 HOR layout.
    //HOR Layout consists of 2 Vlayouts.
    //Vlayout consists of LABEL and Frame
    QHBoxLayout* main_layout = new QHBoxLayout;
    QVBoxLayout* sub_layout1 = new QVBoxLayout;
    QVBoxLayout* sub_layout2 = new QVBoxLayout;

    //TODO: Cleanup code duplication
    QLabel* original_label = new QLabel(tr("Original"));
    QFrame * original_frame = new QFrame();
    original_frame->setFrameStyle(1);
    original_frame->setMinimumHeight(200);
    original_frame->setMaximumWidth(200);
    sub_layout1->addWidget(original_label);
    sub_layout1->addWidget(original_frame);


    QLabel* blurred_label = new QLabel(tr("Blurred"));
    QFrame * blurred_frame = new QFrame();
    blurred_frame->setFrameStyle(1);
    blurred_frame->setMinimumHeight(200);
    blurred_frame->setMaximumWidth(200);
    sub_layout2->addWidget(blurred_label);
    sub_layout2->addWidget(blurred_frame);

    main_layout->addLayout(sub_layout1);
    main_layout->addLayout(sub_layout2);
    QDialog * main_dialog = new QDialog;
    main_dialog->setLayout(main_layout);
    m_tabwidget->addTab(main_dialog,"No Results");
}

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
