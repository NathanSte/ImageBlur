#include "mainblurrer.h"

#include <QDebug>
#include <QDir>

MainBlurrer::MainBlurrer(QWidget *parent) :
    QDialog(parent)
{
    QIcon *myicon = new QIcon("my_icon.ico");

    this->setWindowIcon(*myicon); //Sets the icon, increases Reference count to icon
    this->setWindowTitle(tr("ImageBlurrer v1.0"));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QGridLayout *subLayoutTop = new QGridLayout;
    QVBoxLayout *subLayoutBottom = new QVBoxLayout;

    QLabel* pHeader = new QLabel(tr("Multi Blur Images"));
    QFont font = pHeader->font();
    font.setBold(true);
    pHeader->setFont(font);

    QLabel* pHeader2 = new QLabel(tr("Input a folder of images and let the blurring begin."));

    QPixmap* qPM = new QPixmap("./Image1.png");
    QLabel* imageLabel = new QLabel();
    imageLabel->setPixmap(qPM->scaled(32,32,Qt::KeepAspectRatio));

    mainLayout->addLayout(subLayoutTop);
    mainLayout->addLayout(subLayoutBottom);

    subLayoutTop->addWidget(imageLabel,0,0,2,1);
    subLayoutTop->addWidget(pHeader,0,1);
    subLayoutTop->addWidget(pHeader2,1,1);

    QFrame * mFrame = new QFrame(this);//Must pass this to maintain parent
    mFrame->setFrameStyle(1);
    subLayoutBottom->addWidget(mFrame);
    this->setLayout(mainLayout);

}

MainBlurrer::~MainBlurrer()
{

}
