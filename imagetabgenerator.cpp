/*
 * “Copyright (c) <current year> Medicim NV. All rights reserved.
 * Confidential and for internal use only.
 * The content of this document constitutes proprietary
 * information of the Nobel Biocare group of companies.
 * Any disclosure, copying, distribution or use of any parts of the content of
 * this document by unauthorized parties is strictly prohibited.”
 */
#include "imagetabgenerator.h"

namespace imagehelpspace
{

MyCustomTabWidget *ImageTabGenerator::generateSingleTabFromPath(QString path)
{
    MyCustomTabWidget * new_tab = new MyCustomTabWidget();
    new_tab->initImage(path);
    return new_tab;
}

}
