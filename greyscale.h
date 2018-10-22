#ifndef GREYSCALE_H
#define GREYSCALE_H

#include <QUndoCommand>
#include <QImage>

class Greyscale : public QUndoCommand
{
public:
    explicit Greyscale(QImage& img) :
        m_Image(img)
    {
        setText("greyscale");
    }
    virtual void undo();
    virtual void redo();
 private:
     QImage& m_Image;
     QImage m_Saved;
     // Weight values for greyscale
     const double m_RedAdj = 0.30;
     const double m_GreenAdj = 0.59;
     const double m_BlueAdj = 0.11;
     void adjust();
};

#endif // GREYSCALE_H
