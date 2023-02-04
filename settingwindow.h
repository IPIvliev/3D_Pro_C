#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H

#include <QMainWindow>
#include "aboutwindow.h"
#include "advwindow.h"
#include "wifiwindow.h"
#include "loginwindow.h"
#include "firmwarewindow.h"

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = nullptr);
    ~SettingWindow();

private:
    Ui::SettingWindow *ui;

    AboutWindow *aboutWindow;
    AdvWindow *advWindow;
    WifiWindow *wifiWindow;
    LoginWindow *loginWindow;
    FirmwareWindow *firmwareWindow;

signals:
    void mainWindow();
private slots:
    void on_backButton_clicked();
    void on_aboutButton_clicked();
    void on_advButton_clicked();
    void on_loginButton_clicked();
    void on_netButton_clicked();
    void on_firmwareButton_clicked();
    void changeConnection(bool result);

};

#endif // SETTINGWINDOW_H
