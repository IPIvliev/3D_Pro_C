#ifndef CHOOSEPRINTWINDOW_H
#define CHOOSEPRINTWINDOW_H

#include <QMainWindow>
#include "usbprintwindow.h"
#include "accountprintwindow.h"

namespace Ui {
class ChoosePrintWindow;
}

class ChoosePrintWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChoosePrintWindow(QWidget *parent = nullptr);
    ~ChoosePrintWindow();

private slots:
    void on_backButton_clicked();

    void on_usbButton_clicked();

    void on_accountButton_clicked();

private:
    Ui::ChoosePrintWindow *ui;

    UsbPrintWindow *usbPrintWindow;
    AccountPrintWindow * accountPrintWindow;

signals:
    void mainWindow();

private slots:
    void changeConnection(bool result);
};

#endif // CHOOSEPRINTWINDOW_H
