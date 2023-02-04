#include "servicewindow.h"
#include "ui_service_window.h"
#include "modules/led.cpp"
#include "modules/vat.cpp"
#include "modules/connection.h"

ServiceWindow::ServiceWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ServiceWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTitleHint);

    zWindow = new ZWindow();
    connect(zWindow, &ZWindow::serviceWindow, this, &ServiceWindow::show);

    vatWindow = new VatWindow();
    connect(vatWindow, &VatWindow::serviceWindow, this, &ServiceWindow::show);

    connect(&CONNECTION, SIGNAL(checkConnection(bool)), SLOT(changeConnection(bool)));
}

ServiceWindow::~ServiceWindow()
{
    turnoffLed();
    turnoffVat();
    delete ui;
}

void ServiceWindow::on_backButton_clicked()
{
    emit mainWindow();
    turnoffLed();
    turnoffVat();
    this->close();
}


void ServiceWindow::on_moveButton_clicked()
{
    zWindow->show();
    turnoffLed();
    turnoffVat();
}


void ServiceWindow::on_vatButton_clicked()
{
    vatWindow->show();
    turnoffLed();
    turnoffVat();
}


void ServiceWindow::on_clearButton_clicked()
{
    QPixmap led_label_on (":/res/img/clearButton_on.png");
    QPixmap led_label_off (":/res/img/clearButton_off.png");

    if (led == false) {
        ui->clearLabel->setPixmap(led_label_on);
        ledToggle(true);
    } else {
        ui->clearLabel->setPixmap(led_label_off);
        ledToggle(false);
    }
    led = !led;
}


void ServiceWindow::on_toggleButton_clicked()
{
    QPixmap vat_label_on (":/res/img/vatButton_on.png");
    QPixmap vat_label_off (":/res/img/vatButton_off.png");

    if (vat == false) {
        ui->toggleLabel->setPixmap(vat_label_on);
        vatToggle(true);
    } else {
        ui->toggleLabel->setPixmap(vat_label_off);
        vatToggle(false);
    }
    vat = !vat;
}

void ServiceWindow::turnoffLed()
{
    if (led == true) {
        QPixmap led_label_off (":/res/img/clearButton_off.png");
        ui->clearLabel->setPixmap(led_label_off);
        ledToggle(false);
        led = false;
    }
}

void ServiceWindow::turnoffVat()
{
    if (vat == true) {
        QPixmap vat_label_off (":/res/img/vatButton_off.png");
        ui->toggleLabel->setPixmap(vat_label_off);
        vatToggle(false);
        vat = false;
    }
}

void ServiceWindow::changeConnection(bool result)
{
    qDebug() << "Have a signal in Service. The status is" << result;
    if (result == true)
    {
        QPixmap Good (":/res/img/goodSignal.png");
        ui->connectionWifi->setPixmap(Good);
    } else {
        QPixmap Bad (":/res/img/noSignal.png");
        ui->connectionWifi->setPixmap(Bad);
    }
}
