#ifndef IMAGETABGENERATOR_H
#define IMAGETABGENERATOR_H

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
#endif // IMAGETABGENERATOR_H
