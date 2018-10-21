#ifndef UNDOMAINWIN_H
#define UNDOMAINWIN_H

#include <QMainWindow>
#include <QUndoStack>

class QWidget;
class QLabel;
class QImage;
class QEvent;

namespace Ui {
class UndoMainWin;
}

class UndoMainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit UndoMainWin(QWidget *parent = nullptr);
    ~UndoMainWin();

private slots:
    void on_saveButton_clicked();
    void on_openButton_clicked();
    void on_quitButton_clicked();
    void on_undoButton_clicked();
    void on_redoButton_clicked();
    void on_verticalMirrorButton_clicked();
    void on_horizontalMirrorButton_clicked();
    void on_adjustColorButton_clicked();
    void on_actionOpen_triggered();
    void on_actionClose_triggered();
    void on_actionSave_triggered();
    void on_actionAdjust_Color_triggered();
    void on_actionQuit_triggered();
    void on_actionUndo_The_Last_Action_triggered();
    void on_actionMirror_Pixels_Horizontal_triggered();
    void on_actionMirror_Pixels_Vertical_triggered();

private:
    void displayImage(const QImage &img);
    Ui::UndoMainWin *ui;
    QLabel* m_ImageDisplay;
    QImage m_Image;
    QUndoStack m_Stack;
};

#endif // UNDOMAINWIN_H
