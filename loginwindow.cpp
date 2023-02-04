#include "loginwindow.h"
#include "ui_login_window.h"
#include <QString>
#include <iostream>
#include "modules/connection.h"

using namespace std;

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTitleHint);

    settings = new QSettings("settings.conf", QSettings::IniFormat);

    loadSettings();

    connect(&CONNECTION, SIGNAL(checkConnection(bool)), SLOT(changeConnection(bool)));

}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::loadSettings()
{
    QString auth = settings->value("auth").toString();
    QString email = settings->value("email").toString();
    QString login = settings->value("login").toString();
    if (auth == "true") {
        ui->textBrowser->hide();
        ui->errorText->hide();
        ui->loginButton->hide();
        ui->loginLabel->hide();
        ui->passwordFieldLabel->hide();
        ui->passwordText->hide();
        ui->loginFieldLabel->setDisabled(true);
        ui->loginText->setDisabled(true);
        ui->successText->show();
        ui->logoutButton->show();
        ui->logoutLabel->show();
        ui->accountEmail->setText(email);
        ui->accountEmail->show();
        ui->loginText->setText(login);
      } else {
        ui->logoutButton->hide();
        ui->logoutLabel->hide();
        ui->successText->hide();
        ui->accountEmail->hide();
    }

    bool connection = true;

    if (connection == false) {
      ui->loginText->hide();
      ui->loginFieldLabel->hide();
      ui->passwordText->hide();
      ui->passwordFieldLabel->hide();
    }
    else {
      ui->noNetLabel->hide();
    }
}

void LoginWindow::on_backButton_clicked()
{
    emit settingWindow();
    this->close();
}

void LoginWindow::changeConnection(bool result)
{
    qDebug() << "Have a signal in Login. The status is" << result;
    if (result == true)
    {
        QPixmap Good (":/res/img/goodSignal.png");
        ui->connectionWifi->setPixmap(Good);
    } else {
        QPixmap Bad (":/res/img/noSignal.png");
        ui->connectionWifi->setPixmap(Bad);
    }
}

