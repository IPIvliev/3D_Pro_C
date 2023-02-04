#include "zwindow.h"
#include "ui_z_window.h"
#include "modules/connection.h"

ZWindow::ZWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ZWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTitleHint);

    connect(&CONNECTION, SIGNAL(checkConnection(bool)), SLOT(changeConnection(bool)));

}

ZWindow::~ZWindow()
{
    delete ui;
}

void ZWindow::on_backButton_clicked()
{
    emit serviceWindow();
    this->close();
}


void ZWindow::on_aButton_clicked()
{
    QPixmap Label10 (":/res/img/selector_10.png");
    ui->stepLabel->setPixmap(Label10);
}

void ZWindow::on_bButton_clicked()
{
    QPixmap Label50 (":/res/img/selector_50.png");
    ui->stepLabel->setPixmap(Label50);
}

void ZWindow::on_cButton_clicked()
{
    QPixmap Label100 (":/res/img/selector_100.png");
    ui->stepLabel->setPixmap(Label100);
}

void ZWindow::on_dButton_clicked()
{
    QPixmap Label1000 (":/res/img/selector_1000.png");
    ui->stepLabel->setPixmap(Label1000);
}

void ZWindow::on_stepButton_clicked()
{
    QPixmap ModelLabel (":/res/img/z_move_step.png");
    ui->modeLabel->setPixmap(ModelLabel);
    ui->stepLabel->show();
}


void ZWindow::on_stopButton_clicked()
{
    QPixmap ModelLabel (":/res/img/z_move_stop.png");
    ui->modeLabel->setPixmap(ModelLabel);
    ui->stepLabel->hide();
}


void ZWindow::on_upButton_pressed()
{
    QPixmap UpLabel (":/res/img/z_up_active.png");
    ui->upLabel->setPixmap(UpLabel);
}


void ZWindow::on_upButton_released()
{
    QPixmap UpLabel (":/res/img/z_up.png");
    ui->upLabel->setPixmap(UpLabel);
}

void ZWindow::on_zstopButton_pressed()
{
    QPixmap StopLabel (":/res/img/z_stop_active.png");
    ui->stopLabel->setPixmap(StopLabel);
}


void ZWindow::on_zstopButton_released()
{
    QPixmap StopLabel (":/res/img/z_stop.png");
    ui->stopLabel->setPixmap(StopLabel);
}

void ZWindow::on_downButton_pressed()
{
    QPixmap DownLabel (":/res/img/z_down_active.png");
    ui->downLabel->setPixmap(DownLabel);
}


void ZWindow::on_downButton_released()
{
    QPixmap DownLabel (":/res/img/z_down.png");
    ui->downLabel->setPixmap(DownLabel);
}

void ZWindow::changeConnection(bool result)
{
    qDebug() << "Have a signal in ZMove. The status is" << result;
    if (result == true)
    {
        QPixmap Good (":/res/img/goodSignal.png");
        ui->connectionWifi->setPixmap(Good);
    } else {
        QPixmap Bad (":/res/img/noSignal.png");
        ui->connectionWifi->setPixmap(Bad);
    }
}
