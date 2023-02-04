#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <servicewindow.h>
#include <settingwindow.h>
#include "chooseprintwindow.h"
#include "usbprintwindow.h"
#include "modules/connection.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setSettings();
    void loadSettings();

private slots:
    void on_serviceButton_clicked();

    void on_settingButton_clicked();

    void on_lightButton_clicked();

    void on_doorButton_clicked();

    void on_printButton_clicked();

    void changeConnection(bool result);

private:
    Ui::MainWindow *ui;
    QSettings *settings;

    ServiceWindow *serviceWindow;
    SettingWindow *settingWindow;
    ChoosePrintWindow *choosePrintWindow;
    UsbPrintWindow *usbPrintWindow;

};
#endif // MAIN_WINDOW_H
