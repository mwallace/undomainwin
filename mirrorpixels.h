#ifndef MIRRORPIXELS_H
#define MIRRORPIXELS_H

#include <QUndoCommand>
#include <QImage>

class MirrorPixels : public QUndoCommand
{
public:
    MirrorPixels(QImage& img, bool horiz): m_Image(img), m_Saved(img.size(),
      img.format()), m_Horizontal(horiz)
    {
        setText(QString("mirror pixels around %1 line")
                .arg(horiz ?"horizontal":"vertical"));
    }
    virtual void undo();
    virtual void redo();
private:
   QImage& m_Image;
   QImage m_Saved;
   bool m_Horizontal;
   void reflect();
};

#endif // MIRRORPIXELS_H
