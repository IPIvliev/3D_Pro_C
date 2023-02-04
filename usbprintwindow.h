#ifndef USBPRINTWINDOW_H
#define USBPRINTWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>

namespace Ui {
class UsbPrintWindow;
}

class UsbPrintWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UsbPrintWindow(QWidget *parent = nullptr);
    ~UsbPrintWindow();

private slots:
    void on_backButton_clicked();
    void changeConnection(bool result);

    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::UsbPrintWindow *ui;

    QFileSystemModel *filesModel;

signals:
    void mainWindow();
    void choosePrintWindow();
};

#endif // USBPRINTWINDOW_H
