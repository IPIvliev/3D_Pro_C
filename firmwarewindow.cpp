#include "firmwarewindow.h"
#include "ui_firmware_window.h"
#include "modules/connection.h"

FirmwareWindow::FirmwareWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FirmwareWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTitleHint);

    connect(&CONNECTION, SIGNAL(checkConnection(bool)), SLOT(changeConnection(bool)));
}

FirmwareWindow::~FirmwareWindow()
{
    delete ui;
}

void FirmwareWindow::on_backButton_clicked()
{
    emit settingWindow();
    this->close();
}

void FirmwareWindow::changeConnection(bool result)
{
    qDebug() << "Have a signal in Firmware. The status is" << result;
    if (result == true)
    {
        QPixmap Good (":/res/img/goodSignal.png");
        ui->connectionWifi->setPixmap(Good);
    } else {
        QPixmap Bad (":/res/img/noSignal.png");
        ui->connectionWifi->setPixmap(Bad);
    }
}

