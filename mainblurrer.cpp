#include "mainblurrer.h"

#include <QDebug>
#include <QDir>

MainBlurrer::MainBlurrer(QWidget *parent) :
    QDialog(parent)
{
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

    QComboBox* cb1 = new QComboBox();
    cb1->addItem("1");
    cb1->addItem("3");
    cb1->addItem("6");

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

    QHBoxLayout* bottom_Hlayout3 = new QHBoxLayout;




    QFrame * mFrame = new QFrame(this);//Must pass this to maintain parent
    mFrame->setFrameStyle(1);
    mFrame->setLayout(bottom_layout);//This frame has the bottom layout

    bottom_layout->addLayout(bottom_Hlayout1);
    bottom_layout->addLayout(bottom_Hlayout2);
    bottom_layout->addLayout(bottom_Hlayout3);



   // bottom_layout->addLayout(bottom_Hlayout3);

    main_layout->addLayout(header_layout);
    main_layout->addWidget(mFrame);

    this->setLayout(main_layout);

}

MainBlurrer::~MainBlurrer()
{

}
