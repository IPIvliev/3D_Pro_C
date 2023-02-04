#include "chooseprintwindow.h"
#include "ui_choose_print_window.h"
#include "modules/connection.h"

ChoosePrintWindow::ChoosePrintWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChoosePrintWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTitleHint);

    usbPrintWindow = new UsbPrintWindow();
    connect(usbPrintWindow, &UsbPrintWindow::choosePrintWindow, this, &ChoosePrintWindow::show);

    accountPrintWindow = new AccountPrintWindow();
    connect(accountPrintWindow, &AccountPrintWindow::choosePrintWindow, this, &ChoosePrintWindow::show);

    connect(&CONNECTION, SIGNAL(checkConnection(bool)), SLOT(changeConnection(bool)));
}

ChoosePrintWindow::~ChoosePrintWindow()
{
    delete ui;
}

void ChoosePrintWindow::on_backButton_clicked()
{
    this->close();
    emit mainWindow();
}


void ChoosePrintWindow::on_usbButton_clicked()
{
    usbPrintWindow->show();
//    this->close();
}


void ChoosePrintWindow::on_accountButton_clicked()
{
    accountPrintWindow->show();
}

void ChoosePrintWindow::changeConnection(bool result)
{
    qDebug() << "Have a signal in ChoosePrint. The status is" << result;
    if (result == true)
    {
        QPixmap Good (":/res/img/goodSignal.png");
        ui->connectionWifi->setPixmap(Good);
    } else {
        QPixmap Bad (":/res/img/noSignal.png");
        ui->connectionWifi->setPixmap(Bad);
    }
}

