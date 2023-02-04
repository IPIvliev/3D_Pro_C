#include "wifiwindow.h"
#include "ui_wifi_window.h"
#include "modules/connection.h"

WifiWindow::WifiWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WifiWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTitleHint);

    connect(&CONNECTION, SIGNAL(checkConnection(bool)), SLOT(changeConnection(bool)));

}

WifiWindow::~WifiWindow()
{
    delete ui;
}

void WifiWindow::on_backButton_clicked()
{
    emit settingWindow();
    this->close();
}

void WifiWindow::changeConnection(bool result)
{
    qDebug() << "Have a signal in WiFi. The status is" << result;
    if (result == true)
    {
        QPixmap Good (":/res/img/goodSignal.png");
        ui->connectionWifi->setPixmap(Good);
    } else {
        QPixmap Bad (":/res/img/noSignal.png");
        ui->connectionWifi->setPixmap(Bad);
    }
}

