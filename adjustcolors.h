#ifndef ADJUSTCOLORS_H
#define ADJUSTCOLORS_H

#include <QUndoCommand>
#include <QImage>

class AdjustColors : public QUndoCommand
{
public:
   AdjustColors(QImage& img, const double radj, const double gadj, const double badj)
     : m_Image(img), m_Saved(img.size(), img.format()), m_RedAdj(radj),
     m_GreenAdj(gadj), m_BlueAdj(badj)   {setText("adjust colors"); }
   virtual void undo();
   virtual void redo();
private:
    QImage& m_Image;
    QImage m_Saved;
    const double m_RedAdj;
    const double m_GreenAdj;
    const double m_BlueAdj;
    void adjust(const double radj, const double gadj, const double badj);
};

#endif // ADJUSTCOLORS_H
