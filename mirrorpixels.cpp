#include "mirrorpixels.h"

void MirrorPixels::reflect()
{
    m_Saved = m_Image.copy(QRect());
    const int h(m_Image.height());
    const int w(m_Image.width());
    QRgb pix;
    if (m_Horizontal)
    {
       int midpt = h / 2;
       for(int x = 0; x < w; ++x)
       {
          for(int y = 0; y < midpt; ++y)
          {
             pix = m_Image.pixel(x,y);
             m_Image.setPixel(x,h - 1 - y,pix);
          }
       }
    }
    else
    {
       int midpt = w / 2;
       for(int y = 0; y < h; ++y)
       {
          for(int x = 0; x < midpt; ++x)
          {
             pix = m_Image.pixel(x,y);
             m_Image.setPixel(w-1-x,y,pix);
          }
       }
    }
}

void MirrorPixels::redo()
{
   reflect();
}


void MirrorPixels::undo()
{
    m_Image = m_Saved.copy(QRect());
}
