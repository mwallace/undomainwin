#include <QFileDialog>
#include "undomainwin.h"
#include "ui_undomainwin.h"

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

}

void UndoMainWin::on_openButton_clicked()
{
    on_actionOpen_triggered();
}

void UndoMainWin::on_quitButton_clicked()
{

}

void UndoMainWin::on_undoButton_clicked()
{

}

void UndoMainWin::on_redoButton_clicked()
{

}

void UndoMainWin::on_verticalMirrorButton_clicked()
{

}

void UndoMainWin::on_horizontalMirrorButton_clicked()
{

}

void UndoMainWin::on_adjustColorButton_clicked()
{

}

void UndoMainWin::on_actionOpen_triggered()
{
    m_Image.load(QFileDialog::getOpenFileName());
    displayImage(m_Image);
}

void UndoMainWin::on_actionClose_triggered()
{

}

void UndoMainWin::on_actionSave_triggered()
{

}

void UndoMainWin::on_actionAdjust_Color_triggered()
{

}

void UndoMainWin::on_actionQuit_triggered()
{

}

void UndoMainWin::on_actionUndo_The_Last_Action_triggered()
{

}

void UndoMainWin::on_actionMirror_Pixels_Horizontal_triggered()
{

}

void UndoMainWin::on_actionMirror_Pixels_Vertical_triggered()
{

}
