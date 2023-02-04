#include "main_window.h"
#include "ui_main_window.h"
#include <QString>
#include "modules/light.cpp"
#include "modules/door.cpp"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTitleHint);

    settings = new QSettings("settings.conf", QSettings::IniFormat);

    loadSettings();

    serviceWindow = new ServiceWindow();
    connect(serviceWindow, &ServiceWindow::mainWindow, this, &MainWindow::show);

    settingWindow = new SettingWindow();
    connect(settingWindow, &SettingWindow::mainWindow, this, &MainWindow::show);

    choosePrintWindow = new ChoosePrintWindow();
    connect(choosePrintWindow, &ChoosePrintWindow::mainWindow, this, &MainWindow::show);

    usbPrintWindow = new UsbPrintWindow();
    connect(usbPrintWindow, &UsbPrintWindow::mainWindow, this, &MainWindow::show);

    connect(&CONNECTION, SIGNAL(checkConnection(bool)), SLOT(changeConnection(bool)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSettings()
{
//    settings->setValue("door", "close");
//    settings->setValue("light", "false");
}

void MainWindow::loadSettings()
{
    QPixmap door_label_open (":/res/img/doorButton_on.png");
    QString door = settings->value("door").toString();
    if (door == "open") {
        ui->doorLabel->setPixmap(door_label_open);
        doorToggle(true);
    }
    QPixmap light_label_on (":/res/img/lightButton_on.png");
    QString light = settings->value("light").toString();
    if (light == "true") {
        ui->lightLabel->setPixmap(light_label_on);
        lightToggle(true);
    }
}


void MainWindow::on_serviceButton_clicked()
{
    serviceWindow->show();
//    this->close();
}


void MainWindow::on_settingButton_clicked()
{
    settingWindow->show();
//    this->close();
}


void MainWindow::on_lightButton_clicked()
{
    QPixmap light_label_on (":/res/img/lightButton_on.png");
    QPixmap light_label_off (":/res/img/lightButton_off.png");
    QString light = settings->value("light").toString();
    if (light == "false") {
        ui->lightLabel->setPixmap(light_label_on);
        settings->setValue("light", "true");
        lightToggle(true);
    } else {
        ui->lightLabel->setPixmap(light_label_off);
        settings->setValue("light", "false");
        ui->statusBar->showMessage("Закрыто");
        lightToggle(false);
    }
}


void MainWindow::on_doorButton_clicked()
{
    QPixmap door_label_open (":/res/img/doorButton_on.png");
    QPixmap door_label_close (":/res/img/doorButton_off.png");
    QString door = settings->value("door").toString();
    if (door == "close") {
        ui->doorLabel->setPixmap(door_label_open);
        settings->setValue("door", "open");
        doorToggle(true);
    } else {
        ui->doorLabel->setPixmap(door_label_close);
        settings->setValue("door", "close");
        doorToggle(false);
    }
}


void MainWindow::on_printButton_clicked()
{
    choosePrintWindow->show();
}

void MainWindow::changeConnection(bool result)
{
    qDebug() << "Have a signal in Main. The status is" << result;
    if (result == true)
    {
        QPixmap Good (":/res/img/goodSignal.png");
        ui->connectionWifi->setPixmap(Good);
    } else {
        QPixmap Bad (":/res/img/noSignal.png");
        ui->connectionWifi->setPixmap(Bad);
    }
}
