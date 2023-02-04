#include "accountprintwindow.h"
#include "ui_account_print_window.h"
#include "modules/connection.h"

AccountPrintWindow::AccountPrintWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AccountPrintWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTitleHint);

    connect(&CONNECTION, SIGNAL(checkConnection(bool)), SLOT(changeConnection(bool)));
}

AccountPrintWindow::~AccountPrintWindow()
{
    delete ui;
}

void AccountPrintWindow::on_backButton_clicked()
{
    emit choosePrintWindow();
    this->close();
}

void AccountPrintWindow::changeConnection(bool result)
{
    qDebug() << "Have a signal in Account. The status is" << result;
    if (result == true)
    {
        QPixmap Good (":/res/img/goodSignal.png");
        ui->connectionWifi->setPixmap(Good);
    } else {
        QPixmap Bad (":/res/img/noSignal.png");
        ui->connectionWifi->setPixmap(Bad);
    }
}
