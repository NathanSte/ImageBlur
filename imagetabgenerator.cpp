#include "imagetabgenerator.h"

namespace imagehelpspace
{
ImageTabGenerator::ImageTabGenerator()
{

}

QDialog *ImageTabGenerator::generateSingleTabFromPath(QString path)
{
    /* In: Path of the image
     * Returns: Dialog widget containing original image and empty blurred image
    */
    QDialog * image_tab = new QDialog;

    QHBoxLayout* main_layout = new QHBoxLayout;
    QVBoxLayout* sub_layout1 = new QVBoxLayout;
    QVBoxLayout* sub_layout2 = new QVBoxLayout;

    QPixmap * image = new QPixmap(path);

    QLabel* image_scene = new QLabel("image");
    image_scene->setPixmap(image->scaled(200,200));

    QLabel* original_label = new QLabel(QObject::tr("Original"));

    sub_layout1->addWidget(original_label);
    sub_layout1->addWidget(image_scene);

    QLabel* blurred_label = new QLabel(QObject::tr("Blurred"));
    QFrame * blurred_frame = new QFrame();
    blurred_frame->setFrameStyle(1);
    blurred_frame->setMinimumHeight(200);
    blurred_frame->setMaximumWidth(200);
    sub_layout2->addWidget(blurred_label);
    sub_layout2->addWidget(blurred_frame);

    main_layout->addLayout(sub_layout1);
    main_layout->addLayout(sub_layout2);
    image_tab->setLayout(main_layout);
    return image_tab;


}
}
