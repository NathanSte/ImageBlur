/*
 * “Copyright (c) <current year> Medicim NV. All rights reserved.
 * Confidential and for internal use only.
 * The content of this document constitutes proprietary
 * information of the Nobel Biocare group of companies.
 * Any disclosure, copying, distribution or use of any parts of the content of
 * this document by unauthorized parties is strictly prohibited.”
 */
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
            int p1r = qRed(image->pixel(x - 1, y - 1));
            int p1g = qGreen(image->pixel(x - 1, y - 1));
            int p1b = qBlue(image->pixel(x - 1, y - 1));

            int p2r = qRed(image->pixel(x - 1, y - 1));
            int p2g = qGreen(image->pixel(x - 1, y - 1));
            int p2b = qBlue(image->pixel(x - 1, y - 1));

            int p3r = qRed(image->pixel(x - 1, y - 1));
            int p3g = qGreen(image->pixel(x - 1, y - 1));
            int p3b = qBlue(image->pixel(x - 1, y - 1));

            int p4r = qRed(image->pixel(x - 1, y - 1));
            int p4g = qGreen(image->pixel(x - 1, y - 1));
            int p4b = qBlue(image->pixel(x - 1, y - 1));

            int p5r = qRed(image->pixel(x - 1, y - 1));
            int p5g = qGreen(image->pixel(x - 1, y - 1));
            int p5b = qBlue(image->pixel(x - 1, y - 1));

            int p6r = qRed(image->pixel(x - 1, y - 1));
            int p6g = qGreen(image->pixel(x - 1, y - 1));
            int p6b = qBlue(image->pixel(x - 1, y - 1));

            int p7r = qRed(image->pixel(x - 1, y - 1));
            int p7g = qGreen(image->pixel(x - 1, y - 1));
            int p7b = qBlue(image->pixel(x - 1, y - 1));

            int p8r = qRed(image->pixel(x - 1, y - 1));
            int p8g = qGreen(image->pixel(x - 1, y - 1));
            int p8b = qBlue(image->pixel(x - 1, y - 1));

            int p9r = qRed(image->pixel(x - 1, y - 1));
            int p9g = qGreen(image->pixel(x - 1, y - 1));
            int p9b = qBlue(image->pixel(x - 1, y - 1));

            int pr = (p1r + p2r + p3r + p4r + p5r + p6r + p7r + p8r + p9r) / 9;
            int pg = (p1g + p2g + p3g + p4g + p5g + p6g + p7g + p8g + p9g) / 9;
            int pb = (p1b + p2b + p3b + p4b + p5b + p6b + p7b + p8b + p9b) / 9;

            tmp.setPixel(x, y, qRgb(pr, pg, pb));
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
    for (int x = 0; x < image->width(); x++)
    {
        for (int y = 0; y < image->height(); y++)
        {
            QRgb pixel = image->pixel(x, y);
            image->setPixel(x, y, convertGrayScale(pixel));
        }
    }
}
