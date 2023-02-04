#include "vatwindow.h"
#include "ui_vat_window.h"
#include "modules/connection.h"

VatWindow::VatWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VatWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTitleHint);

    connect(&CONNECTION, SIGNAL(checkConnection(bool)), SLOT(changeConnection(bool)));

}

VatWindow::~VatWindow()
{
    delete ui;
}

void VatWindow::on_backButton_clicked()
{
    emit serviceWindow();
    this->close();

}

void VatWindow::on_inButton_pressed()
{
    QPixmap inLabel (":/res/img/vat_in_active.png");
    ui->inLabel->setPixmap(inLabel);
    qDebug() << "Кнопка заливки полимера нажата";
}


void VatWindow::on_inButton_released()
{
    QPixmap inLabel (":/res/img/vat_in.png");
    ui->inLabel->setPixmap(inLabel);
    qDebug() << "Кнопка заливки полимера отпущена";
}


void VatWindow::on_outButton_pressed()
{
    QPixmap outLabel (":/res/img/vat_out_active.png");
    ui->outLabel->setPixmap(outLabel);
    qDebug() << "Кнопка слива полимера нажата";
}


void VatWindow::on_outButton_released()
{
    QPixmap outLabel (":/res/img/vat_out.png");
    ui->outLabel->setPixmap(outLabel);
    qDebug() << "Кнопка слива полимера отпущена";
}

void VatWindow::changeConnection(bool result)
{
    qDebug() << "Have a signal in Vat. The status is" << result;
    if (result == true)
    {
        QPixmap Good (":/res/img/goodSignal.png");
        ui->connectionWifi->setPixmap(Good);
    } else {
        QPixmap Bad (":/res/img/noSignal.png");
        ui->connectionWifi->setPixmap(Bad);
    }
}

