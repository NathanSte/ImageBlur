#include "helper.h"

void
blurImage(QImage * image)
{
    // Temporary image.
    QImage tmp = QImage(image->width(), image->height(), image->format());

    // Simple moving average filter with 3x3 kernel and equal weight.
    // 1 2 3
    // 4 5 6
    // 7 8 9

    // Then do a simple moving average filter.
    for (int x = 1; x < (image->width() - 1); x++)
    {
        for (int y = 1; y < (image->height() - 1); y++)
        {
            // Get the original surrounding pixel values,
            // all RGB values are equal because of our own grayscaling function.
            int p1 = qRed(image->pixel(x - 1, y - 1));
            int p2 = qRed(image->pixel(x, y - 1));
            int p3 = qRed(image->pixel(x + 1, y - 1));
            int p4 = qRed(image->pixel(x - 1, y));
            int p5 = qRed(image->pixel(x, y));
            int p6 = qRed(image->pixel(x + 1, y));
            int p7 = qRed(image->pixel(x - 1, y + 1));
            int p8 = qRed(image->pixel(x, y - 1));
            int p9 = qRed(image->pixel(x + 1, y + 1));
            int p = (p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8 + p9) / 9;
            tmp.setPixel(x, y, qRgb(p, p, p));
        }
    }

    // Copy restult to original.
    * image = tmp;
}

//--------------------------------------------------------------------------------
QRgb
convertGrayScale(QRgb pixel)
{
    int g = 0.3 * qRed(pixel) + 0.59 * qGreen(pixel) + 0.11 * qBlue(pixel);
    pixel = qRgb(g, g, g);
    return pixel;
}

//--------------------------------------------------------------------------------
void
convertGrayscale(QImage * image)
{
    // Initialize return value.
    bool success = false;

    for (int x = 0; x < image->width(); x++)
    {
        for (int y = 0; y < image->height(); y++)
        {
            QRgb pixel = image->pixel(x, y);
            image->setPixel(x, y, convertGrayScale(pixel));
        }
    }
}
