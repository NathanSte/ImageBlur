#include "mainblurrer.h"

#include <QDebug>
#include <QDir>

MainBlurrer::MainBlurrer(QWidget *parent) :
    QDialog(parent)
{
    m_blur_disable = true;
    m_step_dropdown_disable = true;
    QLabel* label1 = new QLabel(tr("Image Folder"));
    QLabel* label2 = new QLabel(tr("Number of Passes"));
    QLabel* label3 = new QLabel(tr("No Results"));
    QLabel* label4 = new QLabel(tr("Original"));
    QLabel* label5 = new QLabel(tr("Blurred"));
    QLabel* label6 = new QLabel(tr("Total Time"));
    QLabel* label7 = new QLabel(tr("Exit"));

    QLineEdit * line1 = new QLineEdit;

    QPushButton* pb1 = new QPushButton("Set Folder");
    QPushButton* pb2 = new QPushButton("Start Blurring");
    if(m_blur_disable){
        pb2->setDisabled(true);
    }
    //Populate the combobox
    QComboBox* cb1 = new QComboBox();
    for(int i = 1; i<11;i++){
        cb1->addItem(QString::fromStdString(std::to_string(i)));
    }
    cb1->setCurrentIndex(5);//Sets default
    if(m_step_dropdown_disable){
        cb1->setDisabled(true);
    }
    QIcon *myicon = new QIcon("my_icon.ico");

    QLabel* pHeader2 = new QLabel(tr("Input a folder of images and let the blurring begin."));
    QPixmap* qPM = new QPixmap("./Image1.png");

    QLabel* imageLabel = new QLabel();
    imageLabel->setPixmap(qPM->scaled(32,32,Qt::KeepAspectRatio));
    this->setWindowIcon(*myicon); //Sets the icon, increases Reference count to icon
    this->setWindowTitle(tr("ImageBlurrer v1.0"));

    QLabel* pHeader = new QLabel(tr("Multi Blur Images"));
    QFont font = pHeader->font();
    font.setBold(true);
    pHeader->setFont(font);
    pHeader->setMinimumWidth(500);

    QVBoxLayout* main_layout = new QVBoxLayout; //This is the main layout.

    //Populate the header.
    QGridLayout* header_layout = new QGridLayout;//contains the header.
    header_layout->addWidget(imageLabel,0,0,2,1);
    header_layout->addWidget(pHeader,0,1);
    header_layout->addWidget(pHeader2,1,1);

    QVBoxLayout* bottom_layout = new QVBoxLayout;//Contains the rest of the application

    QHBoxLayout* bottom_Hlayout1 = new QHBoxLayout;
    bottom_Hlayout1->addWidget(label1,0,Qt::AlignLeft);
    bottom_Hlayout1->addWidget(line1,0);
    bottom_Hlayout1->addWidget(pb1);

    QHBoxLayout* bottom_Hlayout2 = new QHBoxLayout;
    bottom_Hlayout2->addWidget(label2);
    bottom_Hlayout2->addWidget(cb1);
    bottom_Hlayout2->addWidget(pb2);
    bottom_Hlayout2->addStretch();

    m_tabwidget = new QTabWidget;
    this->initTabWidget();

    QHBoxLayout* bottom_Hlayout3 = new QHBoxLayout;
    bottom_Hlayout3->addWidget(m_tabwidget);

    QHBoxLayout* bottom_Hlayout4 = new QHBoxLayout;
    QPushButton* pb3 = new QPushButton("Exit");
    QObject::connect(pb3,SIGNAL(clicked()),this,SLOT(close()));
    QLabel* timeLabel = new QLabel(tr("Total Time: -"));
    bottom_Hlayout4->addWidget(timeLabel,0,Qt::AlignLeft);
    bottom_Hlayout4->addWidget(pb3,0,Qt::AlignRight);


    QFrame * mFrame = new QFrame(this);//Must pass this to maintain parent
    mFrame->setFrameStyle(1);
    mFrame->setLayout(bottom_layout);//This frame has the bottom layout

    bottom_layout->addLayout(bottom_Hlayout1);
    bottom_layout->addLayout(bottom_Hlayout2);
    bottom_layout->addLayout(bottom_Hlayout3);
    bottom_layout->addLayout(bottom_Hlayout4);



   // bottom_layout->addLayout(bottom_Hlayout3);

    main_layout->addLayout(header_layout);
    main_layout->addWidget(mFrame);

    this->setLayout(main_layout);

}

MainBlurrer::~MainBlurrer()
{

}

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
    QLabel* label1 = new QLabel(tr("Original"));
    QFrame * mFrame = new QFrame();
    mFrame->setFrameStyle(1);
    mFrame->setMinimumHeight(200);
    mFrame->setMaximumWidth(200);
    sub_layout1->addWidget(label1);
    sub_layout1->addWidget(mFrame);


    QLabel* label2 = new QLabel(tr("Blurred"));
    QFrame * mFrame2 = new QFrame();
    mFrame2->setFrameStyle(1);
    mFrame2->setMinimumHeight(200);
    mFrame2->setMaximumWidth(200);
    sub_layout2->addWidget(label2);
    sub_layout2->addWidget(mFrame2);

    main_layout->addLayout(sub_layout1);
    main_layout->addLayout(sub_layout2);
    QDialog * q = new QDialog;
    q->setLayout(main_layout);
    m_tabwidget->addTab(q,"No Results");
}

