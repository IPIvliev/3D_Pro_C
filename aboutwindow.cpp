#include "aboutwindow.h"
#include "ui_about_window.h"
#include "modules/connection.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTitleHint);

    connect(&CONNECTION, SIGNAL(checkConnection(bool)), SLOT(changeConnection(bool)));
}

AboutWindow::~AboutWindow()
{
    delete ui;
}

void AboutWindow::on_backButton_clicked()
{
    emit settingWindow();
    this->close();
}

void AboutWindow::changeConnection(bool result)
{
//    qDebug() << "Have a signal in About. The status is" << result;
    if (result == true)
    {
        QPixmap Good (":/res/img/goodSignal.png");
        ui->connectionWifi->setPixmap(Good);
    } else {
        QPixmap Bad (":/res/img/noSignal.png");
        ui->connectionWifi->setPixmap(Bad);
    }
}

