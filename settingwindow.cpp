#include "settingwindow.h"
#include "ui_setting_window.h"

SettingWindow::SettingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTitleHint);

    aboutWindow = new AboutWindow();
    connect(aboutWindow, &AboutWindow::settingWindow, this, &SettingWindow::show);

    //advWindow = new AdvWindow();
    //connect(advWindow, &AdvWindow::settingWindow, this, &SettingWindow::show);

    wifiWindow = new WifiWindow();
    connect(wifiWindow, &WifiWindow::settingWindow, this, &SettingWindow::show);

    firmwareWindow = new FirmwareWindow();
    connect(firmwareWindow, &FirmwareWindow::settingWindow, this, &SettingWindow::show);

    loginWindow = new LoginWindow();
    connect(loginWindow, &LoginWindow::settingWindow, this, &SettingWindow::show);

    connect(&CONNECTION, SIGNAL(checkConnection(bool)), SLOT(changeConnection(bool)));
}

SettingWindow::~SettingWindow()
{
    delete ui;
}

void SettingWindow::on_backButton_clicked()
{
    emit mainWindow();
    this->close();
}


void SettingWindow::on_aboutButton_clicked()
{
    aboutWindow->show();
}


void SettingWindow::on_advButton_clicked()
{
    advWindow = new AdvWindow();
    advWindow->show();
}


void SettingWindow::on_loginButton_clicked()
{
    loginWindow->show();
}


void SettingWindow::on_netButton_clicked()
{
    wifiWindow->show();
}


void SettingWindow::on_firmwareButton_clicked()
{
    firmwareWindow->show();
}

void SettingWindow::changeConnection(bool result)
{
    qDebug() << "Have a signal in Settings. The status is" << result;
    if (result == true)
    {
        QPixmap Good (":/res/img/goodSignal.png");
        ui->connectionWifi->setPixmap(Good);
    } else {
        QPixmap Bad (":/res/img/noSignal.png");
        ui->connectionWifi->setPixmap(Bad);
    }
}

