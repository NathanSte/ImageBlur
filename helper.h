/*
* Copyright (c) 2012 Medicim NV. All rights reserved.
* Confidential and for internal use only. The content of this document constitutes proprietary
* information of the Nobel Biocare group of companies. Any disclosure, copying, distribution or use of
* any parts of the content of this document by unauthorized parties is strictly prohibited.
*/
#pragma once
// Qt.
#include <QtGui/QImage>
#include <QtGui/QRgb>

//--------------------------------------------------------------------------------
void
blurImage(QImage * image);

//--------------------------------------------------------------------------------
QRgb
convertGrayScale(QRgb pixel);

//--------------------------------------------------------------------------------
void
convertGrayscale(QImage * image);

