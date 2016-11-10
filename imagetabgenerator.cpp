#include "imagetabgenerator.h"

namespace imagehelpspace
{

ImageTabGenerator::ImageTabGenerator()
{

}

MyCustomTabWidget *ImageTabGenerator::generateSingleTabFromPath(QString path)
{
    /* In: Path of the image
     * Returns: Dialog widget containing original image and empty blurred image
    */
    MyCustomTabWidget * new_tab = new MyCustomTabWidget();
    new_tab->setImage(path);
    return new_tab;

}

}
