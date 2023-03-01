#include "usbprintwindow.h"
#include "ui_usb_print_window.h"
#include "modules/connection.h"

UsbPrintWindow::UsbPrintWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UsbPrintWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowTitleHint);

    ui->progressBar->hide();

    connect(&CONNECTION, SIGNAL(checkConnection(bool)), SLOT(changeConnection(bool)));

    QString sPath = "C:/";
    filesModel = new QFileSystemModel(this);
    filesModel->setFilter(QDir::AllEntries | QDir::NoDot);
    filesModel->setRootPath(sPath);
    ui->listView->setModel(filesModel);
    ui->listView->setWordWrap(true);
}

UsbPrintWindow::~UsbPrintWindow()
{
    delete filesModel;
    delete ui;
}

void UsbPrintWindow::on_backButton_clicked()
{
    emit choosePrintWindow();
    this->close();
}

void UsbPrintWindow::changeConnection(bool result)
{
    qDebug() << "Have a signal in USB. The status is" << result;
    if (result == true)
    {
        QPixmap Good (":/res/img/goodSignal.png");
        ui->connectionWifi->setPixmap(Good);
    } else {
        QPixmap Bad (":/res/img/noSignal.png");
        ui->connectionWifi->setPixmap(Bad);
    }
}


void UsbPrintWindow::on_listView_clicked(const QModelIndex &index)
{


    QString sPath = filesModel->fileInfo(index).absoluteFilePath();
    QString ext = filesModel->fileInfo(index).suffix();  // ext = "gz"
    if (ext == "png")
    {
        QString fileName = filesModel -> filePath(index);
        QPixmap pixmap(fileName);

        ui->imageLabel->setPixmap(pixmap);
        ui->imageLabel->resize(pixmap.width(), pixmap.height());
    } else {

        ui->listView->setRootIndex(filesModel->setRootPath(sPath));

    }
}

