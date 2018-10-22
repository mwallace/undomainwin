#include <QRect>
#include <QColor>
#include "adjustcolors.h"

void AdjustColors::adjust(const double radj, const double gadj, const double badj)
{
   const int h(m_Image.height());
   const int w(m_Image.width());
   int r, g, b;
   QRgb oldpix, newpix;
   m_Saved = m_Image.copy(QRect()); // save a copy of entire image
   for(int y = 0; y < h; ++y) {
      for(int x = 0; x < w; ++x) {
         oldpix = m_Image.pixel(x,y);
         r = qRed(oldpix) * radj;
         g = qGreen(oldpix) * gadj;
         b = qBlue(oldpix) * badj;
         newpix = qRgb(r,g,b);
         m_Image.setPixel(x,y,newpix);
      }
   }
}

void AdjustColors::redo()
{
   adjust(m_RedAdj, m_GreenAdj, m_BlueAdj);
}

void AdjustColors::undo()
{
    m_Image = m_Saved.copy(QRect());
}
