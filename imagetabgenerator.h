#ifndef IMAGETABGENERATOR_H
#define IMAGETABGENERATOR_H

#include <QtWidgets>
#include <QObject>
namespace imagehelpspace
{

    class ImageTabGenerator
    {
    public:
        ImageTabGenerator();
        static QDialog* generateSingleTabFromPath(QString path);
    };
}
#endif // IMAGETABGENERATOR_H
