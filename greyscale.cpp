#include "greyscale.h"

void Greyscale::adjust()
{
    const int h(m_Image.height());
    const int w(m_Image.width());
    int r, g, b;
    QRgb oldpix, newpix;
    m_Saved = m_Image.copy(QRect()); // save a copy of entire image
    for(int y = 0; y < h; ++y)
    {
       for(int x = 0; x < w; ++x)
       {
          oldpix = m_Image.pixel(x,y);
          r = qRed(oldpix) * m_RedAdj;
          g = qGreen(oldpix) * m_GreenAdj;
          b = qBlue(oldpix) * m_BlueAdj;
          // Calculate and set luminance for each color
          int luminance = r + g + b;
          newpix = qRgb(luminance, luminance, luminance);
          m_Image.setPixel(x,y,newpix);
       }
    }
}

void Greyscale::redo()
{
   adjust();
}

void Greyscale::undo()
{
    m_Image = m_Saved.copy(QRect());
}
