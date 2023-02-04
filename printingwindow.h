#ifndef PRINTINGWINDOW_H
#define PRINTINGWINDOW_H

#include <QMainWindow>

namespace Ui {
class PrintingWindow;
}

class PrintingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PrintingWindow(QWidget *parent = nullptr);
    ~PrintingWindow();

private:
    Ui::PrintingWindow *ui;
};

#endif // PRINTINGWINDOW_H
