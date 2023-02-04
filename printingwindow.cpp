#include "printingwindow.h"
#include "ui_printing_window.h"

PrintingWindow::PrintingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PrintingWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTitleHint);
}

PrintingWindow::~PrintingWindow()
{
    delete ui;
}
