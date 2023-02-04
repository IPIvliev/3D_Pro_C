#include "advwindow.h"
#include "ui_adv_window.h"
#include "modules/connection.h"
#include "dialog_default_window.h"

AdvWindow::AdvWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdvWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTitleHint);
    setAttribute(Qt::WA_DeleteOnClose);
    settings = new QSettings("settings.conf", QSettings::IniFormat);
    default_settings = new QSettings("default_settings.conf", QSettings::IniFormat);

    loadSettings();

    connect(&CONNECTION, SIGNAL(checkConnection(bool)), SLOT(changeConnection(bool)));

    ui->speedVatSlider->setStyleSheet(
                "QSlider { background: #fff; }"
                "QSlider::groove:horizontal { height: 12px; margin: 0px; border-radius: 5px; background: #B0AEB1; }"
                "QSlider::handle:horizontal { background: #d83a56; border: 4px solid #fff; width: 34px; height: 34px; margin: -16px  0px -13px 0px; border-radius: 20px; }" );
    ui->fullVatSlider->setStyleSheet(
                "QSlider { background: #fff; }"
                "QSlider::groove:horizontal { height: 12px; margin: 0px; border-radius: 5px; background: #B0AEB1; }"
                "QSlider::handle:horizontal { background: #d83a56; border: 4px solid #fff; width: 34px; height: 34px; margin: -16px  0px -13px 0px; border-radius: 20px; }" );
    ui->speedDoorSlider->setStyleSheet(
                "QSlider { background: #fff; }"
                "QSlider::groove:horizontal { height: 12px; margin: 0px; border-radius: 5px; background: #B0AEB1; }"
                "QSlider::handle:horizontal { background: #d83a56; border: 4px solid #fff; width: 34px; height: 34px; margin: -16px  0px -13px 0px; border-radius: 20px; }" );
}

AdvWindow::~AdvWindow()
{
    delete ui;
}

void AdvWindow::loadSettings()
{
    QString upDistance = settings->value("upDistance").toString();
    ui->upText->setText(upDistance);
    QString startVatDelay = settings->value("startVatDelay").toString();
    ui->startVatText->setText(startVatDelay);
    QString finishVatDelay = settings->value("finishVatDelay").toString();
    ui->finishVatText->setText(finishVatDelay);
    QString speedVat = settings->value("speedVat").toString();
    ui->speedVatText->setText(speedVat);
    ui->speedVatSlider->setRange(1, 100);
    ui->speedVatSlider->setValue(speedVat.toInt());
    QString fullVat = settings->value("fullVat").toString();
    ui->fullVatText->setText(fullVat);
    ui->fullVatSlider->setRange(1, 100);
    ui->fullVatSlider->setValue(fullVat.toInt());
    QString speedDoor = settings->value("speedDoor").toString();
    ui->speedDoorText->setText(speedDoor);
    ui->speedDoorSlider->setRange(1, 100);
    ui->speedDoorSlider->setValue(speedDoor.toInt());
}

void AdvWindow::on_backButton_clicked()
{
    emit settingWindow();
    this->close();
}


void AdvWindow::on_upPlusButton_clicked()
{
    float upDistance = ui->upText->text().toFloat();
    upDistance += 0.1;
    QString distance = QString::number(upDistance);
    ui->upText->setText(distance);

    setSaveEnabled();
}


void AdvWindow::on_upMinusButton_clicked()
{
    float upDistance = ui->upText->text().toFloat();
    upDistance -= 0.1;
    if(upDistance < 0.1) {
        upDistance = 0;
    }
    QString distance = QString::number(upDistance);
    ui->upText->setText(distance);

    setSaveEnabled();
}


void AdvWindow::on_startVatMinusButton_clicked()
{
    float startVat = ui->startVatText->text().toFloat();
    startVat -= 0.1;
    if(startVat < 0.1) {
        startVat = 0;
    }
    QString startTime = QString::number(startVat);
    ui->startVatText->setText(startTime);

    setSaveEnabled();
}


void AdvWindow::on_startVatPlusButton_clicked()
{
    float startVat = ui->startVatText->text().toFloat();
    startVat += 0.1;
    QString startTime = QString::number(startVat);
    ui->startVatText->setText(startTime);

    setSaveEnabled();
}


void AdvWindow::on_finishVatMinusButton_clicked()
{
    float finishVat = ui->finishVatText->text().toFloat();
    finishVat -= 0.1;
    if(finishVat < 0.1) {
        finishVat = 0;
    }
    QString finishTime = QString::number(finishVat);
    ui->finishVatText->setText(finishTime);

    setSaveEnabled();
}


void AdvWindow::on_finishVatPlusButton_clicked()
{
    float finishVat = ui->finishVatText->text().toFloat();
    finishVat += 0.1;
    QString finishTime = QString::number(finishVat);
    ui->finishVatText->setText(finishTime);

    setSaveEnabled();
}

void AdvWindow::setSaveEnabled()
{
    ui->saveButton->setEnabled(true);
    ui->saveLabel->setEnabled(true);
}

void AdvWindow::on_saveButton_clicked()
{
    settings->setValue("upDistance", ui->upText->text());
    settings->setValue("startVatDelay", ui->startVatText->text());
    settings->setValue("finishVatDelay", ui->finishVatText->text());
    settings->setValue("speedVat", ui->speedVatText->text());
    settings->setValue("fullVat", ui->fullVatText->text());
    settings->setValue("speedDoor", ui->speedDoorText->text());

    ui->saveButton->setEnabled(false);
    ui->saveLabel->setEnabled(false);
}


void AdvWindow::on_defaultButton_clicked()
{
    DefaultDialog defaultDialog(this);
    defaultDialog.setWindowFlags(Qt::Window);

    if(defaultDialog.exec() == QDialog::Accepted) {

        QString upDistance = default_settings->value("upDistance").toString();
        ui->upText->setText(upDistance);
        QString startVatDelay = default_settings->value("startVatDelay").toString();
        ui->startVatText->setText(startVatDelay);
        QString finishVatDelay = default_settings->value("finishVatDelay").toString();
        ui->finishVatText->setText(finishVatDelay);
        QString speedVat = default_settings->value("speedVat").toString();
        ui->speedVatText->setText(speedVat);
        ui->speedVatSlider->setValue(speedVat.toInt());
        QString fullVat = default_settings->value("fullVat").toString();
        ui->fullVatText->setText(fullVat);
        ui->fullVatSlider->setValue(fullVat.toInt());
        QString speedDoor = default_settings->value("speedDoor").toString();
        ui->speedDoorText->setText(speedDoor);
        ui->speedDoorSlider->setValue(speedDoor.toInt());

        setSaveEnabled();

    }
}


void AdvWindow::on_speedVatSlider_sliderMoved(int value)
{
    ui->speedVatText->setText(QString::number(value));

    setSaveEnabled();
}


void AdvWindow::on_fullVatSlider_sliderMoved(int value)
{
    ui->fullVatText->setText(QString::number(value));

    setSaveEnabled();
}

void AdvWindow::on_speedDoorSlider_sliderMoved(int value)
{
    ui->speedDoorText->setText(QString::number(value));

    setSaveEnabled();
}

void AdvWindow::changeConnection(bool result)
{
    qDebug() << "Have a signal in Advantage. The status is" << result;
    if (result == true)
    {
        QPixmap Good (":/res/img/goodSignal.png");
        ui->connectionWifi->setPixmap(Good);
    } else {
        QPixmap Bad (":/res/img/noSignal.png");
        ui->connectionWifi->setPixmap(Bad);
    }
}
