/*
 * “Copyright (c) <current year> Medicim NV. All rights reserved.
 * Confidential and for internal use only.
 * The content of this document constitutes proprietary
 * information of the Nobel Biocare group of companies.
 * Any disclosure, copying, distribution or use of any parts of the content of
 * this document by unauthorized parties is strictly prohibited.”
 */
#pragma once

#include <QtWidgets>
#include "mycustomtabwidget.h"

namespace imagehelpspace
{
    class ImageTabGenerator
    {
    public:
        ImageTabGenerator();
        static MyCustomTabWidget* generateSingleTabFromPath(QString path);
    };
}
