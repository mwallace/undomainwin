#include <QFileDialog>
#include "undomainwin.h"
#include "ui_undomainwin.h"
#include "adjustcolors.h"

UndoMainWin::UndoMainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UndoMainWin),
    m_ImageDisplay(new QLabel(this)), m_Image(QImage())
{
    ui->setupUi(this);
    m_ImageDisplay->setMinimumSize(640,480);
}

UndoMainWin::~UndoMainWin()
{
    delete ui;
}

void UndoMainWin::displayImage(const QImage &img)
{
    m_ImageDisplay->setPixmap(QPixmap::fromImage(img));
}

void UndoMainWin::on_saveButton_clicked()
{
    on_actionSave_triggered();
}

void UndoMainWin::on_openButton_clicked()
{
    on_actionOpen_triggered();
}

void UndoMainWin::on_quitButton_clicked()
{
    on_actionQuit_triggered();
}

void UndoMainWin::on_undoButton_clicked()
{
    on_actionUndo_The_Last_Action_triggered();
}

void UndoMainWin::on_redoButton_clicked()
{
    on_actionRedo_The_Last_Action_triggered();
}

void UndoMainWin::on_verticalMirrorButton_clicked()
{
    on_actionMirror_Pixels_Vertical_triggered();
}

void UndoMainWin::on_horizontalMirrorButton_clicked()
{
    on_actionMirror_Pixels_Horizontal_triggered();
}

void UndoMainWin::on_adjustColorButton_clicked()
{
    on_actionAdjust_Color_triggered();
}

void UndoMainWin::on_actionOpen_triggered()
{
    m_Image.load(QFileDialog::getOpenFileName());
    displayImage(m_Image);
}

void UndoMainWin::on_actionClose_triggered()
{
    m_ImageDisplay->clear();
    m_Image.allGray();
}

void UndoMainWin::on_actionSave_triggered()
{
    QString filename(QFileDialog::getSaveFileName());
    m_Image.save(filename);
}

void UndoMainWin::on_actionAdjust_Color_triggered()
{
    const double radj(ui->redSpin->value());
    const double gadj(ui->greenSpin->value());
    const double badj(ui->blueSpin->value());
    AdjustColors* ac = new AdjustColors(m_Image, radj, gadj, badj);
    m_Stack.push(ac);
    displayImage(m_Image);
}

void UndoMainWin::on_actionQuit_triggered()
{
        QApplication::quit();
}

void UndoMainWin::on_actionUndo_The_Last_Action_triggered()
{
    m_Stack.undo();
    displayImage(m_Image);
}

void UndoMainWin::on_actionMirror_Pixels_Horizontal_triggered()
{

}

void UndoMainWin::on_actionMirror_Pixels_Vertical_triggered()
{

}

void UndoMainWin::on_actionRedo_The_Last_Action_triggered()
{
    m_Stack.redo();
    displayImage(m_Image);
}
